#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>

#include <functional>
#include <optional>
#include <map>

template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);

 private:
  static void dfsVisit(int x);
  static std::optional<int> dfsFind(int x);

 private:
  static std::map<int, int> vis;
  static TGraph *Graph;
  static std::function<void(int)> Action;
  static std::function<bool(int)> Predicate;
};

template <typename TGraph>
void DepthFirstSearcher<TGraph>::dfsVisit(int x)
{
	if (vis[x]) return ;
	vis[x] = 1;
	Action(x);
	for (int i = 0; i < Graph->outedges[x].size(); i++) 
		dfsVisit(Graph->outedges[x][i].destination);
	return ;
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::dfsFind(int x)
{
	if (vis[x]) return std::nullopt;
	vis[x] = 1;
	if (Predicate(x)) return x;
	std::optional<int> now = std::nullopt;
	for (int i = 0; i < Graph->outedges[x].size(); i++) {
		now = dfsFind(Graph->outedges[x][i].destination);
		if (now != std::nullopt) return now;
	}
	return std::nullopt;
}

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	vis.clear();
	Graph = graph;
	Action = action;
	dfsVisit(start);
	return ;
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	vis.clear();
	Graph = graph;
	Predicate = predicate;
	return dfsFind(start);
}

#endif
