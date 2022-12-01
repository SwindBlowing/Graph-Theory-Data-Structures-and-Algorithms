#ifndef FLOYD_SHORTEST_PATHS_H
#define FLOYD_SHORTEST_PATHS_H

#include <vector>
#include <optional>
#include <map>
#include <cstdio>

#include <Algorithms/MultiSourceShortestPaths.h>
#include <Exceptions/NegativeCycleException.h>

#define MAXN 1005

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph> {
  public:
 	FloydShortestPaths(const TGraph *graph);
	~FloydShortestPaths() {};
  private:
    std::string algorithmName = "Floyd";
};

template <typename TGraph>
FloydShortestPaths<TGraph>::FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
{
	this->reached.clear(); this->dist.clear(); this->preCode.clear();

	std::vector <int> nodes = graph->GetVertices();
	std::vector <WeightedEdge<TValue>> edges = graph->GetEdges();
	for (int ki = 0; ki < nodes.size(); ki++) {
		int k = nodes[ki];
		this->reached[k][k] = 1;
		TValue newTValue = TValue();
		this->dist[k][k] = newTValue;
		this->preCode[k][k] = std::nullopt;
	}
	for (int k = 0; k < edges.size(); k++) {
		int i = edges[k].GetSource(), j = edges[k].GetDestination();
		TValue w = edges[k].GetWeight();
		if (this->reached[i].find(j) == this->reached[i].end() || w < this->dist[i][j]) {
			this->reached[i][j] = 1;
			this->dist[i][j] = w;
			this->preCode[i][j] = i;
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
					|| this->dist[i][k] + this->dist[k][j] < this->dist[i][j]) {
						this->dist[i][j] = this->dist[i][k] + this->dist[k][j];
						this->preCode[i][j] = this->preCode[k][j];
						this->reached[i][j] = 1;
					}
			}
		}
	for (int ki = 0; ki < nodes.size(); ki++) {
		int k = nodes[ki];
		if (this->dist[k][k] < 0) 
			throw NegativeCycleException(algorithmName);
	}
}

#endif