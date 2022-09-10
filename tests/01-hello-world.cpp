#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <assert.h>
#include <iostream>

int main()
{
   /* Graph G = Graph();
    assert(G.AddVertex(1));
    assert(!G.AddVertex(1));
    assert(G.RemoveVertex(1));
    assert(G.AddVertex(2));
    assert(!G.RemoveVertex(1));
    assert(G.AddVertex(3));
    assert(G.AddEdge(2, 3));
    assert(!G.AddEdge(2, 3));
    assert(G.AddVertex(4));
    assert(G.AddVertex(5));
    assert(G.AddEdge(4, 5));
    assert(G.RemoveEdge(2, 3));
    assert(!G.RemoveEdge(2, 3));
    assert(!G.RemoveEdge(2, 4));
    assert(G.CountEdges() == 1);
    assert(G.CountVertices() == 4);
    assert(G.ContainsVertex(4));
    assert(!G.ContainsVertex(1));
    assert(G.ContainsEdge(4, 5));
    assert(!G.ContainsEdge(2, 3));*/

    Graph g; // 创建一张新的图

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
    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetVertices().size() == g.CountVertices()); // 4
    assert(g.GetEdges().size() == 2);
    assert(g.GetIncomingEdges(1).size() == 0);
    assert(g.GetOutgoingEdges(1).size() == 2); // {{1, 2}, {1, 3}}
    //assert(g.RemoveEdge(1, 3) == true);
    //assert(g.RemoveEdge(1, 3) == false);
    assert(g.GetDegree(1) == 2);
    assert(g.GetNeighbors(1).size() == 2); // {2, 3}
    assert(g.GetNeighbors(2).size() == 0);
}