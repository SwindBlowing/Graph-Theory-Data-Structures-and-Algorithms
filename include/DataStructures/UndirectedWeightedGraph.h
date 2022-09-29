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

#endif