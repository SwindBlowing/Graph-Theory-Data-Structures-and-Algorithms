#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS

#define TValue typename TGraph::value_type

#include <vector>
#include <optional>
#include <map>
#include <queue>

#include <Algorithms/ShortestPaths.h>
#include <DataStructures/WeightedEdge.h>
#define MAXN 1005

template <typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
  public:
    typedef bool (ShortestPaths<TGraph>::*fp_Has)(int destination) const;
    typedef std::optional<TValue> (ShortestPaths<TGraph>::*fp_Dis)(int destination) const;
    typedef std::optional<std::vector<int>> (ShortestPaths<TGraph>::*fp_Path)(int destination) const;
	BellmanFordShortestPaths(const TGraph *graph, int source);
	~BellmanFordShortestPaths() {};
  public:
	bool HasPathTo(int destination) const;
	std::optional<TValue> TryGetDistanceTo(int destination) const;
	std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
  private:
	std::map<int, bool> reached;
	std::map<int, TValue> dist;
	std::map<int, std::optional<int>> preCode;
};

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
{
	this->fn_HasPathTo = (fp_Has)(&BellmanFordShortestPaths::HasPathTo);
	this->fn_TryGetDistanceTo = (fp_Dis)(&BellmanFordShortestPaths::TryGetDistanceTo);
	this->fn_TryGetShortestPathTo = (fp_Path)(&BellmanFordShortestPaths::TryGetShortestPathTo);
	reached.clear(); dist.clear(); preCode.clear();
	if (!graph->ContainsVertex(source)) return ;

	std::vector<WeightedEdge<TValue>> edges;
	edges = graph->GetEdges();
	reached[source] = 1;
	dist[source] = TValue();
	preCode[source] = std::nullopt;
	outEdges = graph->GetOutgoingEdges(source);
	for (int i = 1; i <= (graph->CountVertices()) - 1; i++)
		for (int j = 0; j < edges.size(); j++) {
			int x = edges[j].GetSource(), y = edges[j].GetDestination();
			TValue w = edges[j].GetWeight();
			if (reached[x]) {
				//printf("%d %d\n", x, y);
				if (!reached[y] || dist[y] > dist[x] + w) {
					reached[y] = 1;
					dist[y] = dist[x] + w;
					preCode[y] = x;
				}
			}
		}
}

template <typename TGraph>
bool BellmanFordShortestPaths<TGraph>::HasPathTo(int destination) const
{
	if (reached.find(destination) == reached.end()) return 0;
	return reached.at(destination);
}

template <typename TGraph>
std::optional<TValue> BellmanFordShortestPaths<TGraph>::TryGetDistanceTo(int destination) const
{
	if (!HasPathTo(destination)) return std::nullopt;
	return dist.at(destination);
}

template <typename TGraph>
std::optional<std::vector<int>> BellmanFordShortestPaths<TGraph>::TryGetShortestPathTo(int destination) const
{
	if (!HasPathTo(destination)) return std::nullopt;
	std::optional<int> now = destination;
	std::vector<int> ans; ans.clear();
	while (now != std::nullopt) {
		ans.push_back(now.value());
		now = preCode.at(now.value());
	}
	return ans;
}

#endif