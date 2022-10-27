#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <assert.h>
#include <iostream>

void sum(int x)
{
	return ;
}

int main()
{
    UndirectedWeightedGraph<int> g; // 创建一张新的图

    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);

    assert(g.AddEdge(1, 2, 1) == true);
    assert(g.AddEdge(1, 3, 2) == true);

	DepthFirstSearcher<UndirectedWeightedGraph<int>> dfs;
	dfs.VisitAllVertices(&g, 1, sum);

	return ;
}