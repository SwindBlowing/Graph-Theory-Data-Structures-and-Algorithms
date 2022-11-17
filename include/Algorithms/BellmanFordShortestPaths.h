#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS

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
    //typedef bool (ShortestPaths<TGraph>::*fp_Has)(int destination) const;
    //typedef std::optional<TValue> (ShortestPaths<TGraph>::*fp_Dis)(int destination) const;
    //typedef std::optional<std::vector<int>> (ShortestPaths<TGraph>::*fp_Path)(int destination) const;
	BellmanFordShortestPaths(const TGraph *graph, int source);
	~BellmanFordShortestPaths() {};
  //public:
	//bool HasPathTo(int destination) const;
	//std::optional<TValue> TryGetthis->DistanceTo(int destination) const;
	//std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
};

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
{
	//this->fn_HasPathTo = (fp_Has)(&BellmanFordShortestPaths::HasPathTo);
	//this->fn_TryGetthis->DistanceTo = (fp_Dis)(&BellmanFordShortestPaths::TryGetthis->DistanceTo);
	//this->fn_TryGetShortestPathTo = (fp_Path)(&BellmanFordShortestPaths::TryGetShortestPathTo);
	this->reached.clear(); this->dist.clear(); this->preCode.clear();
	if (!graph->ContainsVertex(source)) return ;

	std::vector<WeightedEdge<TValue>> edges;
	edges = graph->GetEdges();
	this->reached[source] = 1;
	const bool fuck = std::is_default_constructible_v<TValue>;
	this->dist[source] = TValue();
	this->preCode[source] = std::nullopt;
	for (int i = 1; i <= (graph->CountVertices()) - 1; i++) {
		bool isChanged = 0;
		for (int j = 0; j < edges.size(); j++) {
			int x = edges[j].GetSource(), y = edges[j].GetDestination();
			TValue w = edges[j].GetWeight();
			if (this->reached[x]) {
				//printf("%d %d\n", x, y);
				if (!this->reached[y] || this->dist[x] + w < this->dist[y]) {
					isChanged = 1;
					this->reached[y] = 1;
					this->dist[y] = this->dist[x] + w;
					this->preCode[y] = x;
				}
			}
		}
		if (!isChanged) break;
	}
}

/*template <typename TGraph>
bool BellmanFordShortestPaths<TGraph>::HasPathTo(int destination) const
{
	if (this->reached.find(destination) == this->reached.end()) return 0;
	return this->reached.at(destination);
}

template <typename TGraph>
std::optional<TValue> BellmanFordShortestPaths<TGraph>::TryGetthis->DistanceTo(int destination) const
{
	if (!HasPathTo(destination)) return std::nullopt;
	return this->dist.at(destination);
}

template <typename TGraph>
std::optional<std::vector<int>> BellmanFordShortestPaths<TGraph>::TryGetShortestPathTo(int destination) const
{
	if (!HasPathTo(destination)) return std::nullopt;
	std::optional<int> now = destination;
	std::vector<int> ans; ans.clear();
	while (now != std::nullopt) {
		ans.push_back(now.value());
		now = this->preCode.at(now.value());
	}
	return ans;
}*/

#endif