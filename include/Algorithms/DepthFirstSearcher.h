#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#define MAXN 1005

template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);

 private:
  static void dfsVisit(int x);
  static std::optional<int> dfsFind(int x);

 private:
  static bool vis[MAXN];
  static const TGraph *Graph = NULL;
  static std::function<void(int)> Action;
  static std::function<bool(int)> predicate;
};

#endif
