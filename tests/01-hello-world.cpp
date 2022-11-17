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
#include <assert.h>
#include <iostream>
#include <vector>

/*void sum(int x)
{
	return ;
}

bool check(int x)
{
	if (x == 2) return 1;
	return 0;
}

static void test1() {
  auto *g1 = new WeightedGraph<int>();
  auto *g2 = new WeightedGraph<int>();
  for (int i = 1; i <= 6; ++i) {
    g1->AddVertex(i);
	g2->AddVertex(i);
  }
  g1->AddEdge(1, 2, 1);
  g1->AddEdge(2, 3, 2);
  g1->AddEdge(3, 4, 3);
  g1->AddEdge(4, 1, 4);
  g1->AddEdge(5, 6, 5);
  g1->AddEdge(6, 5, 6);
  g2->AddEdge(1, 2, 1);
  g2->AddEdge(2, 3, 2);
  g2->AddEdge(3, 4, 3);
  g2->AddEdge(4, 1, 4);
  g2->AddEdge(5, 6, 5);
  g2->AddEdge(6, 5, 6);

  ShortestPaths<WeightedGraph<int>> *p1 = nullptr;
  ShortestPaths<WeightedGraph<int>> *p2 = nullptr;
  //p = new BellmanFordShortestPaths<WeightedGraph<int>>(g, 1);
  for (int i = 1; i <= 6; ++i) {
    p1 = new BellmanFordShortestPaths<WeightedGraph<int>>(g1, i);
	p2 = new DijkstraShortestPaths<WeightedGraph<int>>(g2, i);
    for (int j = 1; j <= 6; ++j) {
	  if (!p1->HasPathTo(j)) printf("%d ", -1);
	  else printf("%d ", p1->TryGetDistanceTo(j).value());
	  if (!p2->HasPathTo(j)) printf("%d ", -1);
	  else printf("%d ", p2->TryGetDistanceTo(j).value());
    }
    printf("\n");
	p1 = new BellmanFordShortestPaths<WeightedGraph<int>>(g1, 1);
	p2 = new DijkstraShortestPaths<WeightedGraph<int>>(g2, 1);
	std::vector <int> now1 = p1->TryGetShortestPathTo(4).value();
	for (int i = 0; i < now1.size(); i++)
		printf("%d ", now1[i]);
	printf("\n");
	std::vector <int> now2 = p2->TryGetShortestPathTo(4).value();
	for (int i = 0; i < now2.size(); i++)
		printf("%d ", now2[i]);
	printf("\n");
    delete p1;
	delete p2;
  }

  delete g1;
  delete g2;
}*/
struct Test {
	int x = 0;
	Test(int i) ;
	//Test() = delete;
	Test operator+(const Test& t);
	bool operator<(const Test& t);
};
int main()
{
	//static_assert(std::is_default_constructible_v<Test>);
	auto *g = new WeightedGraph<Test>();
	ShortestPaths<WeightedGraph<Test>> *p = new DijkstraShortestPaths<WeightedGraph<Test>>(g, 1);
	delete g;
	return 0;
}