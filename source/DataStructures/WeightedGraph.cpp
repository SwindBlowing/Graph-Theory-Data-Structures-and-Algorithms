#include <DataStructures/WeightedGraph.h>

template <typename T>
bool WeightedGraph<T>::AddEdge(int vertex1, int vertex2, T weight)
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    Weights.insert(std::pair<Edge, int>{(Edge){vertex1, vertex2}, weight});
    return 1;
}

template <typename T>
T WeightedGraph<T>::GetWeight(int vertex1, int vertex2) const
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2))
        return 0;
    return Weights.at((Edge){vertex1, vertex2});
}

template <typename T>
std::vector<WeightedEdge<T>> WeightedGraph<T>::GetEdges() const 
{
    std::vector <WeightedEdge<T>> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetEdges();
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge<T>){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}

template <typename T>
std::vector<WeightedEdge<T>> WeightedGraph<T>::GetIncomingEdges(int vertex) const 
{
    std::vector <WeightedEdge<T>> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetIncomingEdges(vertex);
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge<T>){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}

template <typename T>
std::vector<WeightedEdge<T>> WeightedGraph<T>::GetOutgoingEdges(int vertex) const 
{
    std::vector <WeightedEdge<T>> wedges; wedges.clear();
    std::vector <Edge> edges = Graph::GetOutgoingEdges(vertex);
    for (auto t = edges.begin(); t != edges.end(); t++)
        wedges.push_back((WeightedEdge<T>){t->GetSource(), t->GetDestination(), Weights.at(*t)});
    return wedges;
}