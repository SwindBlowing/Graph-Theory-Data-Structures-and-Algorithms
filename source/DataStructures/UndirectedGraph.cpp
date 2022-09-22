#include <DataStructures/UndirectedGraph.h>

/*bool UndirectedGraph::AddEdge(int vertex1, int vertex2) 
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    if (vertex2 != vertex1) Graph::AddEdge(vertex2, vertex1);
    else selfLoop[vertex1]++;
    return 1;
}

bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2) 
{
    if (!Graph::RemoveEdge(vertex1, vertex2)) return 0;
    if (vertex2 != vertex1) Graph::RemoveEdge(vertex2, vertex1);
    else selfLoop[vertex1]--;
    return 1;
}

int UndirectedGraph::CountEdges() const 
{
    return (Graph::CountEdges() + selfLoopNum) / 2;
}

int UndirectedGraph::GetDegree(int vertex) const
{
    return Graph::GetDegree(vertex) + selfLoop[vertex];
}*/