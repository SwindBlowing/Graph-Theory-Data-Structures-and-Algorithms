#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <assert.h>
#include <iostream>

int main()
{
    Graph G = Graph();
    assert(G.AddVertex(1));
    assert(!G.AddVertex(1));
}