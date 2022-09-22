#include <DataStructures/UndirectedGraph.h>

bool UndirectedGraph::AddEdge(int vertex1, int vertex2) 
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    Graph::AddEdge(vertex2, vertex1);
    return 1;
}

bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2) 
{
    if (!Graph::RemoveEdge(vertex1, vertex2)) return 0;
    Graph::RemoveEdge(vertex2, vertex1);
    return 1;
}

int UndirectedGraph::CountEdges() const 
{
    return Graph::CountEdges() / 2;
}

std::vector<Edge> UndirectedGraph::GetEdges() const 
{
    visited.clear();
    std::vector <Edge> now = Graph::GetEdges();
    std::vector <Edge> edges; edges.clear();
    for (auto t = now.begin(); t != now.end(); t++)
        if (!visited[*t]) {
            visited[*t] = 1;
            edges.push_back(*t);
        }
    return edges;
}