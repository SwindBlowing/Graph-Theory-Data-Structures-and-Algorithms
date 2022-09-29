#include <DataStructures/WeightedGraph.h>

template <typename T>
bool WeightedGraph::AddEdge(int vertex1, int vertex2, T weight)
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    Weights.insert(std::pair<Edge, int>{(Edge){vertex1, vertex2}, weight});
    return 1;
}

template <typename T>
T WeightedGraph::GetWeight(int vertex1, int vertex2) const
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2))
        return 0;
    return Weights.at((Edge){vertex1, vertex2});
}

std::vector<WeightedEdge> WeightedGraph::GetEdges() const 
{
    std::vector <WeightedEdge> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetEdges();
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}

std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const 
{
    std::vector <WeightedEdge> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetIncomingEdges(vertex);
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}

std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const 
{
    std::vector <WeightedEdge> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetOutgoingEdges(vertex);
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}