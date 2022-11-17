#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/WeightedEdge.h>
#define MAXN 1005

template <typename T>
class UndirectedWeightedGraph : public WeightedGraph<T> {
 public:
  UndirectedWeightedGraph() {selfLoop.clear();}
  ~UndirectedWeightedGraph() {selfLoop.clear();}
 public:
  typedef T value_type;
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2, T weight) override;
  bool RemoveEdge(int vertex1, int vertex2) override;
 public:
  //int CountVertices() const;
  int CountEdges() const override;
  //bool ContainsVertex(int vertex) const;
  //bool ContainsEdge(int vertex1, int vertex2) const;
  //std::vector<int> GetVertices() const;
  //std::vector<Edge> GetEdges() const;
  //std::vector<Edge> GetIncomingEdges(int vertex) const;
  //std::vector<Edge> GetOutgoingEdges(int vertex) const;
  int GetDegree(int vertex) const override;
  //std::vector<int> GetNeighbors(int vertex) const;
 private:
  std::map <int, int> selfLoop;
  int selfLoopNum = 0;
};

template <typename T>
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
}

#endif