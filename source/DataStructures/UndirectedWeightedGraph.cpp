#include <DataStructures/UndirectedWeightedGraph.h>

bool UndirectedWeightedGraph::AddEdge(int vertex1, int vertex2, int weight) 
{
    if (!WeightedGraph::AddEdge(vertex1, vertex2, weight)) return 0;
    if (vertex2 != vertex1) WeightedGraph::AddEdge(vertex2, vertex1, weight);
    else selfLoop[vertex1]++, selfLoopNum++;
    return 1;
}

bool UndirectedWeightedGraph::RemoveEdge(int vertex1, int vertex2) 
{
    if (!WeightedGraph::RemoveEdge(vertex1, vertex2)) return 0;
    if (vertex2 != vertex1) WeightedGraph::RemoveEdge(vertex2, vertex1);
    else selfLoop[vertex1]--, selfLoopNum--;
    return 1;
}

int UndirectedWeightedGraph::CountEdges() const 
{
    return (WeightedGraph::CountEdges() + selfLoopNum) / 2;
}

int UndirectedWeightedGraph::GetDegree(int vertex) const
{
    int now = WeightedGraph::GetDegree(vertex);
    if (!now) return 0;
    else if (selfLoop.find(vertex) == selfLoop.end()) return now;
    else return now + selfLoop.at(vertex);
}