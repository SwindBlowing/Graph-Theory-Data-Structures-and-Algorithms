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
    assert(G.AddEdge(2, 3));
}