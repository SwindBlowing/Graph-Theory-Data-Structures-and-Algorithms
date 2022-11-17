#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

#define TValue typename TGraph::value_type

template <typename TGraph>
class ShortestPaths {
  static_assert(std::is_default_constructible_v<TValue>, 
		"TValue requires default constructor");
 public:
  ShortestPaths() = delete;
  ShortestPaths(const TGraph *graph, int source) {};
  virtual ~ShortestPaths() {}
  
 public:

  bool HasPathTo(int destination) const
  {
	const bool fuck = std::is_default_constructible_v<TValue>;
 	#if (fuck)
	if (reached.find(destination) == reached.end()) return 0;
	return reached.at(destination);
	#else
	return 1;
	#endif
  };

  std::optional<TValue> TryGetDistanceTo(int destination) const
  {
	const bool fuck = std::is_default_constructible_v<TValue>;
 	#if (fuck)
	if (!HasPathTo(destination)) return std::nullopt;
	return dist.at(destination);
	#else
	return std::nullopt;
	#endif
  };

  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
  {
	const bool fuck = std::is_default_constructible_v<TValue>;
 	#if (fuck)
	if (!HasPathTo(destination)) return std::nullopt;
	std::optional<int> now = destination;
	std::vector<int> ans; ans.clear();
	while (now != std::nullopt) {
		ans.push_back(now.value());
		now = preCode.at(now.value());
	}
	return ans;
	#else
	return std::nullopt;
	#endif
  };
 protected:
  std::map<int, bool> reached;
  std::map<int, TValue> dist;
  std::map<int, std::optional<int>> preCode;

};

#endif
