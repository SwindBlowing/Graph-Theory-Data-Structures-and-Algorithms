#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#define TValue typename TGraph::value_type

#include <vector>
#include <optional>
#include <map>
#include <queue>

#include <Algorithms/ShortestPaths.h>
#include <DataStructures/WeightedEdge.h>
#define MAXN 1005

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph> {
  public:
    typedef bool (ShortestPaths<TGraph>::*fp_Has)(int destination) const;
    typedef std::optional<TValue> (ShortestPaths<TGraph>::*fp_Dis)(int destination) const;
    typedef std::optional<std::vector<int>> (ShortestPaths<TGraph>::*fp_Path)(int destination) const;
	DijkstraShortestPaths(const TGraph *graph, int source);
	~DijkstraShortestPaths() {};
  public:
	bool HasPathTo(int destination) const;
	std::optional<TValue> TryGetDistanceTo(int destination) const;
	std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
  private:
	std::map<int, bool> vis, reached;
	std::map<int, TValue> dist;
	std::map<int, std::optional<int>> preCode;
	std::priority_queue<std::pair<TValue, int>, std::vector<std::pair<TValue, int>>, std::greater<std::pair<TValue, int>>> Q;
};

template <typename TGraph>
DijkstraShortestPaths<TGraph>::DijkstraShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
{
	this->fn_HasPathTo = (fp_Has)(&DijkstraShortestPaths::HasPathTo);
	this->fn_TryGetDistanceTo = (fp_Dis)(&DijkstraShortestPaths::TryGetDistanceTo);
	this->fn_TryGetShortestPathTo = (fp_Path)(&DijkstraShortestPaths::TryGetShortestPathTo);
	vis.clear(); reached.clear(); dist.clear(); preCode.clear();
	while (!Q.empty()) Q.pop();
	if (!graph->ContainsVertex(source)) return ;

	std::vector<WeightedEdge<TValue>> outEdges;
	reached[source] = 1;
	dist[source] = TValue();
	preCode[source] = std::nullopt;
	Q.push({dist[source], source});
	while (!Q.empty()) {
		std::pair<TValue, int> now = Q.top();
		Q.pop();
		if (vis[now.second]) continue;
		vis[now.second] = 1;
		outEdges = graph->GetOutgoingEdges(now.second);
		for (int i = 0; i < outEdges.size(); i++) {
			int y = outEdges[i].GetDestination();
			TValue w = outEdges[i].GetWeight();
			if (!reached[y] || dist[now.second] + w < dist[y]) {
				reached[y] = 1;
				dist[y] = dist[now.second] + w;
				preCode[y] = now.second;
				Q.push({dist[y], y});
			}
		}
	}
}

template <typename TGraph>
bool DijkstraShortestPaths<TGraph>::HasPathTo(int destination) const
{
	if (reached.find(destination) == reached.end()) return 0;
	return reached.at(destination);
}

template <typename TGraph>
std::optional<TValue> DijkstraShortestPaths<TGraph>::TryGetDistanceTo(int destination) const
{
	if (!HasPathTo(destination)) return std::nullopt;
	return dist.at(destination);
}

template <typename TGraph>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph>::TryGetShortestPathTo(int destination) const
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