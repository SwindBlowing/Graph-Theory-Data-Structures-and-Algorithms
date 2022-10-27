#include <Algorithms/DepthFirstSearcher.h>

template <typename TGraph>
static void DepthFirstSearcher::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{

}

template <typename TGraph>
static std::optional<int> DepthFirstSearcher::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}