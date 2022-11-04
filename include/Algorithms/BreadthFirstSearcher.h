#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>

#include <functional>
#include <optional>
#include <queue>
#include <map>

template <typename TGraph>
class BreadthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	if (!graph->ContainsVertex(start)) return ;
	std::vector <int> neighbors;
	std::queue<int> Q;
  	std::map<int, bool> vis;
	vis.clear();
	while (!Q.empty()) Q.pop();
	Q.push(start); vis[start] = 1;
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		action(x);
		neighbors = graph->GetNeighbors(x);
		for (int i = 0; i < neighbors.size(); i++) 
			if (!vis[neighbors[i]]) {
				vis[neighbors[i]] = 1;
				Q.push(neighbors[i]);
			}
	}
	return ;
}

template <typename TGraph>
std::optional<int> BreadthFirstSearcher<TGraph>::TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	if (!graph->ContainsVertex(start)) return std::nullopt;
	std::vector <int> neighbors;
	std::queue<int> Q;
  	std::map<int, bool> vis;
	vis.clear();
	while (!Q.empty()) Q.pop();
	Q.push(start); vis[start] = 1;
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		if (predicate(x)) return x;
		neighbors = graph->GetNeighbors(x);
		for (int i = 0; i < neighbors.size(); i++) 
			if (!vis[neighbors[i]]) {
				vis[neighbors[i]] = 1;
				Q.push(neighbors[i]);
			}
	}
	return std::nullopt;
}

#endif