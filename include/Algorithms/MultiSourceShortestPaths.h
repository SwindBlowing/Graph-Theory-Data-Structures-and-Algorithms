#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>

template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  MultiSourceShortestPaths() = delete;
  explicit MultiSourceShortestPaths(const TGraph *graph);
  virtual ~MultiSourceShortestPaths();
 public:
  bool HasPathOf(int source, int destination) const;
  std::optional<TValue> TryGetDistanceOf(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const;
};

#endif
