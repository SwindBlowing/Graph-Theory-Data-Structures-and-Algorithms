#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <map>
#include <optional>

#define TValue typename TGraph::value_type

template <typename TGraph>
class MultiSourceShortestPaths {
 static_assert(std::is_default_constructible_v<TValue>, 
	"TValue requires default constructor");
 public:
  MultiSourceShortestPaths() = delete;
  explicit MultiSourceShortestPaths(const TGraph *graph) {};
  virtual ~MultiSourceShortestPaths() {};
 public:
  bool HasPathOf(int source, int destination) const
  {
	if (reached.find(source) == reached.end()) return 0;
	if (reached.at(source).find(destination) == reached.at(source).end()) return 0;
	return reached.at(source).at(destination);
  };
  std::optional<TValue> TryGetDistanceOf(int source, int destination) const
  {
	if (!HasPathOf(source, destination)) return std::nullopt;
	return dist.at(source).at(destination);
  };
  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const
  {
	if (!HasPathOf(source, destination)) return std::nullopt;
	std::optional<int> now = destination;
	std::vector<int> ans; ans.clear();
	while (now != std::nullopt) {
		ans.push_back(now.value());
		now = preCode.at(source).at(now.value());
	}
	return ans;
  };
 protected:
  std::map <int, std::map <int, bool>> reached;
  std::map <int, std::map <int, TValue>> dist;
  std::map <int, std::map <int, std::optional<int>>> preCode;
};

#endif
