#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#define MAXN 1005

template <typename T>
class WeightedGraph : public Graph {
 public:
  WeightedGraph() {Weights.clear();}
  ~WeightedGraph() {Weights.clear();}
 public:
  const bool fuck = std::is_default_constructible_v<TValue>;
  typedef T value_type;
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  virtual bool AddEdge(int vertex1, int vertex2, T weight);
  //bool RemoveEdge(int vertex1, int vertex2);
 public:
  //int CountVertices() const;
  //int CountEdges() const;
  //bool ContainsVertex(int vertex) const;
  //bool ContainsEdge(int vertex1, int vertex2) const;
  T GetWeight(int vertex1, int vertex2) const;
  //std::vector<int> GetVertices() const;
  std::vector<WeightedEdge<T>> GetEdges() const;
  std::vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const;
  //int GetDegree(int vertex) const;
  //std::vector<int> GetNeighbors(int vertex) const;

 private:
  //std::set <int> vertices;
  std::map <Edge, T> Weights;
  //std::map <int, int> index, outdex;
  //int vertexNum = 0, edgeNum = 0;
};
#if (fuck)
template <typename T>
bool WeightedGraph<T>::AddEdge(int vertex1, int vertex2, T weight)
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    Weights.insert(std::pair<Edge, T>{(Edge){vertex1, vertex2}, weight});
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
#endif

#endif
