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
  bool vis[MAXN];
  TGraph *Graph = NULL;
  std::function<void(int)> Action;
  std::function<bool(int)> Predicate;
};

#endif
