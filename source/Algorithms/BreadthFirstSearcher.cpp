#include <Algorithms/BreadthFirstSearcher.h>

template <typename TGraph>
static void BreadthFirstSearcher::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	action(start);
}

template <typename TGraph>
static std::optional<int> BreadthFirstSearcher::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	predicate(start);
}