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

	std::vector<WeightedEdge<TValue>> outEdges;
	std::vector<WeightedEdge<TValue>> edgePile;
	std::vector<WeightedEdge<TValue>> newEdges;
	edgePile.clear(); newEdges.clear();
	reached[source] = 1;
	dist[source] = TValue();
	preCode[source] = std::nullopt;
	outEdges = graph->GetOutgoingEdges(source);
	for (int i = 0; i < outEdges.size(); i++)
		edgePile.push_back(outEdges[i]);
	for (int i = 1; i <= (graph->CountVertices()) - 1; i++) {
		bool isChanged = 0;
		newEdges.clear();
		for (int j = 0; j < edgePile.size(); j++) {
			int x = edgePile[j].GetSource(), y = edgePile[j].GetDestination();
			TValue w = edgePile[j].GetWeight();
			if (reached[x]) {
				//printf("%d %d\n", x, y);
				if (!reached[y] || dist[y] > dist[x] + w) {
					if (!reached[y]) {
						outEdges = graph->GetOutgoingEdges(y);
						for (int i = 0; i < outEdges.size(); i++)
							newEdges.push_back(outEdges[i]);
					}
					isChanged = 1;
					reached[y] = 1;
					dist[y] = dist[x] + w;
					preCode[y] = x;
				}
			}
		}
		if (!isChanged) break;
		for (int j = 0; j < newEdges.size(); j++)
			edgePile.push_back(newEdges[j]);
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