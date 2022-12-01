#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <Algorithms/ShortestPaths.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/DijkstraShortestPaths.h>
#include <Algorithms/MultiSourceShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>
#include <Exceptions/GLException.h>
#include <Exceptions/NegativeCycleException.h>
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
  auto *g = new WeightedGraph<float>();
  for (int i = 1; i <= 6; ++i) {
	g->AddVertex(i);
  }
  //g->AddEdge(1, 2, 1);
  g->AddEdge(2, 3, 2);
  g->AddEdge(3, 4, 3);
  g->AddEdge(4, 1, 4);
  g->AddEdge(5, 6, 5);
  g->AddEdge(6, 5, 6);
  g->AddEdge(1, 2, -1);
  g->AddEdge(2, 1, -1);

  MultiSourceShortestPaths<WeightedGraph<float>> *p = nullptr;
  p = new FloydShortestPaths<WeightedGraph<float>>(g);
  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
	  if (!p->HasPathOf(i, j)) printf("%d ", -1);
	  else printf("%d ", p->TryGetDistanceOf(i, j).value());
    }
	printf("\n");
  }

  delete g;
}
struct Test {
	//int x = 0;
	Test(int i) ;
	Test() = delete;
	Test operator+(const Test& t);
	bool operator<(const Test& t);
};
int main()
{
	//static_assert(std::is_default_constructible_v<Test>);
	//auto *g = new WeightedGraph<Test>();
	//ShortestPaths<WeightedGraph<Test>> *p = new DijkstraShortestPaths<WeightedGraph<Test>>(g, 1);
	//delete g;
	try {
		test1();
	} catch(const NegativeCycleException& e) {
		std::cout << e << std::endl;
	}
	return 0;
}