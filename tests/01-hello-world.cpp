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
    assert(g.AddVertex(5) == true);

    assert(g.AddEdge(1, 2) == true);
    assert(g.AddEdge(1, 5) == true);
    assert(g.AddEdge(1, 3) == true);
    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.RemoveVertex(1));
    assert(g.GetIncomingEdges(3).size() == 0);
    assert(g.GetNeighbors(1).size() == 0);
}