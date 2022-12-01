#ifndef BELLMANFORD_SHORTEST_PATHS_H
#define BELLMANFORD_SHORTEST_PATHS_H

#include <vector>
#include <optional>
#include <map>
#include <queue>

#include <Algorithms/ShortestPaths.h>
#include <Exceptions/NegativeCycleException.h>

#define MAXN 1005

template <typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
  public:
	BellmanFordShortestPaths(const TGraph *graph, int source);
	~BellmanFordShortestPaths() {};
  private:
	std::string algorithmName = "Bellman-Ford";
};

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
{
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
	for (int j = 0; j < edges.size(); j++) {
		int x = edges[j].GetSource(), y = edges[j].GetDestination();
		TValue w = edges[j].GetWeight();
		if (this->reached[x]) {
			//printf("%d %d\n", x, y);
			if (!this->reached[y] || this->dist[x] + w < this->dist[y]) 
				throw NegativeCycleException(algorithmName);
		}
	}
}

#endif