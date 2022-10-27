#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <map>

template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);

 private:
  static void dfsVisit(int x);
  static std::optional<int> dfsFind(int x);

 private:
  static std::map<int, int> vis;
  static const TGraph *Graph = NULL;
  static std::function<void(int)> Action;
  static std::function<bool(int)> Predicate;
};

#endif
