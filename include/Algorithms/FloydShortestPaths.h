#ifndef FLOYD_SHORTEST_PATHS_H
#define FLOYD_SHORTEST_PATHS_H

#include <vector>
#include <optional>
#include <map>

#include <Algorithms/MultiSourceShortestPaths.h>

#define MAXN 1005

template <typename TGraph>
class FloydShortestPaths : public ShortestPaths<TGraph> {
  public:
 	FloydShortestPaths(const TGraph *graph);
	~FloydShortestPaths() {};
};

template <typename TGraph>
FloydShortestPaths<TGraph>::FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
{
	this->reached.clear(); this->dist.clear(); this->preCode.clear();

	std::vector <int> nodes = GetVertices();
	for (int ki = 0, k = nodes[ki]; ki < nodes.size(); ki++, k = nodes[ki]) {
		this->reached[k].insert(std::pair<int, bool> {k, 1});
		TValue newTValue = TValue();
		this->dist[k].insert(std::pair<int, bool> {k, newTValue});
		this->preCode[k].insert(std::pair<int, std::optional<int>> {k, std::nullopt});
	}
	std::vector<WeightedEdge<TValue>> outEdges;
	for (int ki = 0, k = nodes[ki]; ki < nodes.size(); ki++, k = nodes[ki])
		for (int ii = 0, i = nodes[ii]; ii < nodes.size(); ii++, i = nodes[ii]) {
			if (this->reached[i].find(k) == this->reached[i].end()) continue;
			outEdges = graph->GetOutgoingEdges(i);
			for (int l = 0; l < outEdges.size(); l++) {
				int j = outEdges[l].GetDestination();
				TValue w = outEdges[l].GetWeight();
				if (this->reached[k].find(j) == this->reached[k].end()) continue;
				if (this->reached[i].find(j) == this->reached[i].end()
					|| this->dist[i].at(k) + this->dist[k].at(j) < this->dist[i].at(j) ) {
						if (this->reached[i].find(j) == this->reached[i].end)
							this->reached[i].insert(std::pair<int, TValue> {j, this->dist[i].at(k) + this->dist[k].at(j)});
						else this->reached[i].find(j)->second = this->dist[i].at(k) + this->dist[k].at(j);
						this->preCode[i][j] = k;
						this->reached[i][j] = 1;
					}
			}
		}
}

#endif