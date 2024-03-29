#include <DataStructures/UndirectedWeightedGraph.h>

/*template <typename T>
bool UndirectedWeightedGraph<T>::AddEdge(int vertex1, int vertex2, T weight) 
{
    if (!WeightedGraph<T>::AddEdge(vertex1, vertex2, weight)) return 0;
    if (vertex2 != vertex1) WeightedGraph<T>::AddEdge(vertex2, vertex1, weight);
    else selfLoop[vertex1]++, selfLoopNum++;
    return 1;
}

template <typename T>
bool UndirectedWeightedGraph<T>::RemoveEdge(int vertex1, int vertex2) 
{
    if (!WeightedGraph<T>::RemoveEdge(vertex1, vertex2)) return 0;
    if (vertex2 != vertex1) WeightedGraph<T>::RemoveEdge(vertex2, vertex1);
    else selfLoop[vertex1]--, selfLoopNum--;
    return 1;
}

template <typename T>
int UndirectedWeightedGraph<T>::CountEdges() const 
{
    return (WeightedGraph<T>::CountEdges() + selfLoopNum) / 2;
}

template <typename T>
int UndirectedWeightedGraph<T>::GetDegree(int vertex) const
{
    int now = WeightedGraph<T>::GetDegree(vertex);
    if (!now) return 0;
    else if (selfLoop.find(vertex) == selfLoop.end()) return now;
    else return now + selfLoop.at(vertex);
}*/