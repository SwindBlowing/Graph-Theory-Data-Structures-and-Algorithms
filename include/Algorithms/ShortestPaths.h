#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

#define TValue typename TGraph::value_type

template <typename TGraph>
class ShortestPaths {
 public:
  typedef bool (ShortestPaths::*fp_Has)(int destination) const;
  typedef std::optional<TValue> (ShortestPaths::*fp_Dis)(int destination) const;
  typedef std::optional<std::vector<int>> (ShortestPaths::*fp_Path)(int destination) const;
  ShortestPaths() = delete;
  ShortestPaths(const TGraph *graph, int source) 
  {
	static_assert(std::is_default_constructible<TValue>::value, 
		"TValue requires default constructor");
  }
  virtual ~ShortestPaths() {}
  
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

 protected:
  fp_Has fn_HasPathTo;
  fp_Dis fn_TryGetDistanceTo;
  fp_Path fn_TryGetShortestPathTo;

};

#endif
