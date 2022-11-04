#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include <vector>
#include <optional>

#include <ShortestPaths.h>

template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph<TValue>, TValue> {
  public:
	DijkstraShortestPaths(const TGraph<TValue> *graph, int source);
	~DijkstraShortestPaths() override;
  public:
	bool HasPathTo(int destination) const;
	std::optional<TValue> TryGetDistanceTo(int destination) const;
	std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
}

template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph<TValue>, TValue>::DijkstraShortestPaths(const TGraph<TValue> *graph, int source)
{
	this->fn_HasPathTo = (pfn)(&DijkstraShortestPaths::HasPathTo);
	this->fn_TryGetDistanceTo = (pfn)(&DijkstraShortestPaths::TryGetDistanceTo);
	this->fn_TryGetShortestPathTo = (pfn)(&DijkstraShortestPaths::TryGetShortestPathTo);
}

template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph<TValue>, TValue>::~DijkstraShortestPaths()
{

}

template <template<typename> class TGraph, typename TValue>
bool DijkstraShortestPaths<TGraph<TValue>, TValue>::HasPathTo(int destination) const
{
	return 1;
}

template <template<typename> class TGraph, typename TValue>
std::optional<TValue> DijkstraShortestPaths<TGraph<TValue>, TValue>::TryGetDistanceTo(int destination) const
{
	return std::nullopt;
}

template <template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph<TValue>, TValue>::TryGetShortestPathTo(int destination) const
{
	return std::nullopt;
}

#endif