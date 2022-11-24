#ifndef FLOYD_SHORTEST_PATHS_H
#define FLOYD_SHORTEST_PATHS_H

#include <vector>
#include <optional>
#include <map>
#include <cstdio>

#include <Algorithms/MultiSourceShortestPaths.h>

#define MAXN 1005

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph> {
  public:
 	FloydShortestPaths(const TGraph *graph);
	~FloydShortestPaths() {};
};

template <typename TGraph>
FloydShortestPaths<TGraph>::FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
{
	this->reached.clear(); this->dist.clear(); this->preCode.clear();

	std::vector <int> nodes = graph->GetVertices();
	std::vector <WeightedEdge<TValue>> edges = graph->GetEdges();
	for (int ki = 0; ki < nodes.size(); ki++) {
		int k = nodes[ki];
		this->reached[k].insert(std::pair<int, bool> {k, 1});
		TValue newTValue = TValue();
		this->dist[k].insert(std::pair<int, TValue> {k, newTValue});
		this->preCode[k].insert(std::pair<int, std::optional<int>> {k, std::nullopt});
	}
	for (int k = 0; k < edges.size(); k++) {
		int i = edges[k].GetSource(), j = edges[k].GetDestination();
		TValue w = edges[k].GetWeight();
		if (this->reached[i].find(j) == this->reached[i].end() || w < this->dist[i].at(j)) {
			this->reached[i].insert(std::pair<int, bool> {j, 1});
			this->dist[i].insert(std::pair<int, TValue> {j, w});
			this->preCode[i].insert(std::pair<int, std::optional<int>> {j, i});
		}
	}

	for (int ki = 0; ki < nodes.size(); ki++)
		for (int ii = 0; ii < nodes.size(); ii++) {
			int k = nodes[ki], i = nodes[ii];
			if (this->reached[i].find(k) == this->reached[i].end()) continue;
			for (int ji = 0; ji < nodes.size(); ji++) {
				int j = nodes[ji];
				if (this->reached[k].find(j) == this->reached[k].end()) continue;
				if (this->reached[i].find(j) == this->reached[i].end()
					|| this->dist[i].at(k) + this->dist[k].at(j) < this->dist[i].at(j) ) {
						if (this->reached[i].find(j) == this->reached[i].end())
							this->dist[i].insert(std::pair<int, TValue> {j, this->dist[i].at(k) + this->dist[k].at(j)});
						else this->dist[i].find(j)->second = this->dist[i].at(k) + this->dist[k].at(j);
						this->preCode[i][j] = k;
						this->reached[i][j] = 1;
					}
			}
		}
}

#endif