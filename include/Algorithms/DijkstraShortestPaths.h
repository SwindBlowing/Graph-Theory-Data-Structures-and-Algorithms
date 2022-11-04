#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include <vector>
#include <optional>

#include <Algorithms/ShortestPaths.h>

template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue> {
  public:
    typedef bool (*fp_Has)(int destination) const;
    typedef std::optional<TValue> (*fp_Dis)(int destination) const;
    typedef std::optional<std::vector<int>> (*fp_Path)(int destination) const;
	DijkstraShortestPaths(const TGraph<TValue> *graph, int source);
	~DijkstraShortestPaths() override;
  public:
	bool HasPathTo(int destination) const;
	std::optional<TValue> TryGetDistanceTo(int destination) const;
	std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
};

template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(const TGraph<TValue> *graph, int source) : ShortestPaths<TGraph, TValue>(graph, source)
{
	this->fn_HasPathTo = (fp_Has)(&DijkstraShortestPaths::HasPathTo);
	this->fn_TryGetDistanceTo = (fp_Dis)(&DijkstraShortestPaths::TryGetDistanceTo);
	this->fn_TryGetShortestPathTo = (fp_Path)(&DijkstraShortestPaths::TryGetShortestPathTo);
}

template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::~DijkstraShortestPaths()
{

}

template <template<typename> class TGraph, typename TValue>
bool DijkstraShortestPaths<TGraph, TValue>::HasPathTo(int destination) const
{
	return 1;
}

template <template<typename> class TGraph, typename TValue>
std::optional<TValue> DijkstraShortestPaths<TGraph, TValue>::TryGetDistanceTo(int destination) const
{
	return std::nullopt;
}

template <template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph, TValue>::TryGetShortestPathTo(int destination) const
{
	return std::nullopt;
}

#endif