#include <Algorithms/DepthFirstSearcher.h>
#include <string.h>

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	this->graph = graph;
	this->action = action;

	memset(vis, 0, sizeof(vis));
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{

}