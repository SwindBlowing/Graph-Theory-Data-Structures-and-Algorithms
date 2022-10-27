#include <Algorithms/DepthFirstSearcher.h>
#include <string.h>

template <typename TGraph>
void DepthFirstSearcher<TGraph>::dfsVisit(int x)
{
	if (vis[x]) return ;
	vis[x] = 1;
	Action(x);
	for (int i =0; i < Graph->outedges[x].size(); i++) 
		dfs(Graph, Graph->outedges[x][i].destination, Action);
	return ;
}

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	memset(vis, 0, sizeof(vis));
	Graph = graph;
	Action = action;
	dfsVisit(start);
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}