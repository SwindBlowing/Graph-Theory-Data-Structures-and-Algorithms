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

class WeightedGraph : public Graph {
 public:
  WeightedGraph() {inEdges.clear(); outEdges.clear();}
  ~WeightedGraph() {inEdges.clear(); outEdges.clear();}
 public:
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2, int weight);
  //bool RemoveEdge(int vertex1, int vertex2);
 public:
  //int CountVertices() const;
  //int CountEdges() const;
  //bool ContainsVertex(int vertex) const;
  //bool ContainsEdge(int vertex1, int vertex2) const;
  int GetWeight(int vertex1, int vertex2) const;
  //std::vector<int> GetVertices() const;
  std::vector<WeightedEdge> GetEdges() const;
  std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
  //int GetDegree(int vertex) const;
  //std::vector<int> GetNeighbors(int vertex) const;

 private:
  //std::set <int> vertices;
  std::map <Edge, int> Weights;
  //std::map <int, int> index, outdex;
  //int vertexNum = 0, edgeNum = 0;
};

#endif
