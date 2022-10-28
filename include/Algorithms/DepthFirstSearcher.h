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
#include <stack>

template <typename TGraph>
class DepthFirstSearcher
{
public:
	static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
	static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);

private:
	static std::stack<int> S;
	static std::map<int, int> vis;
};

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	vis.clear();
	while (!S.empty()) S.pop();
	S.push(start);
	vis[start] = 1;
	int x;
	while (!S.empty())
	{
		x = S.top();
		S.pop();
		action(x);
		for (int i = 0; i < graph->outedges[x].size(); i++)
			if (!vis[graph->outedges[x][i].destination])
			{
				vis[graph->outedges[x][i].destination] = 1;
				S.push(graph->outedges[x][i].destination);
			}
	}
	return;
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	vis.clear();
	while (!S.empty()) S.pop();
	S.push(start);
	vis[start] = 1;
	int x;
	while (!S.empty())
	{
		x = S.top();
		S.pop();
		if (predicate(x))
			return x;
		for (int i = 0; i < graph->outedges[x].size(); i++)
			if (!vis[graph->outedges[x][i].destination])
			{
				vis[graph->outedges[x][i].destination] = 1;
				S.push(graph->outedges[x][i].destination);
			}
	}
	return std::nullopt;
}

#endif
