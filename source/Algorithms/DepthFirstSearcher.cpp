#include <Algorithms/DepthFirstSearcher.h>
#include <string.h>

template <typename TGraph>
void dfs(const TGraph *graph, int x, std::function<void(int)> action)
{

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