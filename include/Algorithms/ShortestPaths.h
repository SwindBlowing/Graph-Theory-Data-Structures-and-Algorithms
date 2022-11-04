#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

template <template<typename> class TGraph, typename TValue>
class ShortestPaths {
 public:
  typedef void (ShortestPaths::*pfn)();
  ShortestPaths() = delete;
  ShortestPaths(const TGraph<TValue> *graph, int source);
  virtual ~ShortestPaths();
 public:
  bool HasPathTo(int destination) const
  {
	assert(fn_HasPathTo != NULL);
	return (this->*fn_HasPathTo)(destination);
  }
  std::optional<TValue> TryGetDistanceTo(int destination) const
  {
	assert(fn_TryGetDistanceTo != NULL);
	return (this->*fn_TryGetDistanceTo)(destination);
  }
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
  {
	assert(fn_TryGetShortestPathTo != NULL);
	return (this->*fn_TryGetShortestPathTo)(destination);
  }
 public:
  pfn fn_HasPathTo, fn_TryGetDistanceTo, fn_TryGetShortestPathTo;
};

#endif
