#include <Algorithms/BreadthFirstSearcher.h>

/*template <typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
	vis.clear();
	while (!Q.empty()) Q.pop();
	Q.push(start); vis[start] = 1;
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		action(x);
		for (int i = 0; i < graph->outedges[x].size(); i++) 
			if (!vis[graph->outedges[x][i].destination]) {
				vis[graph->outedges[x][i].destination] = 1;
				Q.push(graph->outedges[x][i].destination);
			}
	}
	return ;
}

template <typename TGraph>
std::optional<int> BreadthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
	vis.clear();
	while (!Q.empty()) Q.pop();
	Q.push(start); vis[start] = 1;
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		if (predicate(x)) return x;
		for (int i = 0; i < graph->outedges[x].size(); i++) 
			if (!vis[graph->outedges[x][i].destination]) {
				vis[graph->outedges[x][i].destination] = 1;
				Q.push(graph->outedges[x][i].destination);
			}
	}
	return std::nullopt;
}*/