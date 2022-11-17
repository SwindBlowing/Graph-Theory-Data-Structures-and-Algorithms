#ifndef DIJKSTRA_SHORTEST_PATHS_H
#define DIJKSTRA_SHORTEST_PATHS_H

#include <vector>
#include <optional>
#include <map>

#include <ShortestPaths.h>

#define MAXN 1005

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph> {
  public:
 	DijkstraShortestPaths(const TGraph *graph, int source);
	~DijkstraShortestPaths() {};
  private:
	std::map<int, bool> vis;
};

template <typename TGraph>
DijkstraShortestPaths<TGraph>::DijkstraShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
{
	vis.clear(); this->reached.clear(); this->dist.clear(); this->preCode.clear();
	if (!graph->ContainsVertex(source)) return ;

	std::vector<WeightedEdge<TValue>> outEdges;
	this->reached[source] = 1;
	TValue newTValue = TValue();
	this->dist.insert(std::pair<int, TValue>{source, newTValue});
	this->preCode[source] = std::nullopt;
	std::vector<int> vertices;
	vertices = graph->GetVertices();
	for (int i = 1; i < graph->CountVertices(); i++) {
		bool first = 1;
		TValue now = TValue();
		int nowNode = 0;
		for (int j = 0; j < vertices.size(); j++) 
			if (!vis[vertices[j]] && this->reached[vertices[j]]) {
				if (first) {
					first = 0;
					now = this->dist.at(vertices[j]);
					nowNode = vertices[j];
				}
				else if (this->dist.at(vertices[j]) < now) {
					now = this->dist.at(vertices[j]);
					nowNode = vertices[j];
				}
			}
		vis[nowNode] = 1;
		outEdges = graph->GetOutgoingEdges(nowNode);
		for (int i = 0; i < outEdges.size(); i++) {
			int y = outEdges[i].GetDestination();
			TValue w = outEdges[i].GetWeight();
			if (!this->reached[y] || this->dist.at(nowNode) + w < this->dist.at(y)) {
				if (!this->reached[y]) this->dist.insert(std::pair<int, TValue>{y, this->dist.at(nowNode) + w});
				else this->dist.find(y)->second = this->dist.at(nowNode) + w;
				this->reached[y] = 1;
				this->preCode[y] = nowNode;
			}
		}
	}
}

#endif