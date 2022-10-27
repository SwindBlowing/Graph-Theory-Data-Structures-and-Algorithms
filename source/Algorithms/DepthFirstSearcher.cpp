#include <Algorithms/DepthFirstSearcher.h>
#include <string.h>

template <typename TGraph>
void dfs(const TGraph *graph, int x, std::function<void(int)> action)
{
	if (vis[x]) return ;
	vis[x] = 1;
	action(x);
	for (int i =0; i < graph->outedges[x].size(); i++) 
		dfs(graph, graph->outedges[x][i].destination, action);
}

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	memset(vis, 0, sizeof(vis));
	dfs(graph, start, action);
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}