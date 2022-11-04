#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <Algorithms/ShortestPaths.h>
#include <Algorithms/DijkstraShortestPaths.h>
#include <assert.h>
#include <iostream>
#include <vector>

void sum(int x)
{
	return ;
}

bool check(int x)
{
	if (x == 2) return 1;
	return 0;
}

static void test1() {
  auto *g = new WeightedGraph<int>();
  for (int i = 1; i <= 6; ++i) {
    g->AddVertex(i);
  }
  g->AddEdge(1, 2, 1);
  g->AddEdge(2, 3, 2);
  g->AddEdge(3, 4, 3);
  g->AddEdge(4, 1, 4);
  g->AddEdge(5, 6, 5);
  g->AddEdge(6, 5, 6);

  ShortestPaths<WeightedGraph, int> *p = nullptr;
  for (int i = 1; i <= 6; ++i) {
    p = new DijkstraShortestPaths<WeightedGraph, int>(g, i);
    for (int j = 1; j <= 6; ++j) {
	  if (!p->HasPathTo(j)) printf("%d ", -1);
	  else printf("%d ", p->TryGetDistanceTo(j).value());
    }
    printf("\n");
	p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
	std::vector <int> now = p->TryGetShortestPathTo(4).value();
	for (int i = 0; i < now.size(); i++)
		printf("%d ", now[i]);
    delete p;
  }

  delete g;
}

int main()
{
	test1();
	return 0;
}