#include <Algorithms/DepthFirstSearcher.h>

void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	memset(vis, 0, sizeof(vis));
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}