#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <assert.h>
#include <iostream>

int main()
{
    UndirectedGraph g; // 创建一张新的图

    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false); // 3号点已经存在了
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);

    assert(g.AddEdge(1, 2) == true);
    assert(g.AddEdge(1, 3) == true);
    assert(g.AddEdge(2, 5) == false); // 5号点不存在
    assert(g.AddEdge(1, 2) == false);
    assert(g.ContainsEdge(2, 1) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetVertices().size() == g.CountVertices()); // 4
    //assert(g.GetEdges().size() == 2);
    assert(g.GetIncomingEdges(1).size() == 2);
    assert(g.GetOutgoingEdges(1).size() == 2); // {{1, 2}, {1, 3}}
    assert(g.GetDegree(1) == 2);
    assert(g.GetNeighbors(1).size() == 2); // {2, 3}
    assert(g.GetNeighbors(2).size() == 1);

    assert(g.AddEdge(1, 1) == true);
    assert(g.AddEdge(1, 1) == false);
    assert(g.CountEdges() == 3);
    assert(g.GetDegree(1) == 4);

    assert(g.RemoveEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 1) == false);
}