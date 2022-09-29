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
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2, T weight);
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

#endif
