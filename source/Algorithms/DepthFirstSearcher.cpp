#include <Algorithms/DepthFirstSearcher.h>

template <typename TGraph>
static void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{

}

template <typename TGraph>
static std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}