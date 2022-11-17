#ifndef DEPTH_FIRST_SEARCHER_H
#define DEPTH_FIRST_SEARCHER_H

#include <functional>
#include <optional>
#include <map>
#include <stack>

template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	if (!graph->ContainsVertex(start)) return ;
	std::vector<int> neighbors;
	std::stack<int> S;
	std::map<int, int> vis;
	vis.clear();
	while (!S.empty())
		S.pop();
	S.push(start);
	vis[start] = 1;
	int x;
	while (!S.empty())
	{
		x = S.top();
		S.pop();
		action(x);
		neighbors = graph->GetNeighbors(x);
		for (int i = 0; i < neighbors.size(); i++)
			if (!vis[neighbors[i]])
			{
				vis[neighbors[i]] = 1;
				S.push(neighbors[i]);
			}
	}
	return;
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	if (!graph->ContainsVertex(start)) return std::nullopt;
	std::vector<int> neighbors;
	std::stack<int> S;
	std::map<int, int> vis;
	vis.clear();
	while (!S.empty())
		S.pop();
	S.push(start);
	vis[start] = 1;
	int x;
	while (!S.empty())
	{
		x = S.top();
		S.pop();
		if (predicate(x))
			return x;
		neighbors = graph->GetNeighbors(x);
		for (int i = 0; i < neighbors.size(); i++)
			if (!vis[neighbors[i]])
			{
				vis[neighbors[i]] = 1;
				S.push(neighbors[i]);
			}
	}
	return std::nullopt;
}

#endif
