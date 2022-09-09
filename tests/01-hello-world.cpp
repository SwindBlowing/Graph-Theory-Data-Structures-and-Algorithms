#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <assert.h>
#include <iostream>

int main()
{
    Graph G = Graph();
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
}