#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <DataStructures/Edge.h>
#define MAXN 1005

class Graph {
 public:
  Graph();
  ~Graph();
 public:
  bool AddVertex(int vertex);
  bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2);
  bool RemoveEdge(int vertex1, int vertex2);
 public:
  int CountVertices() const;
  int CountEdges() const;
  bool ContainsVertex(int vertex) const;
  bool ContainsEdge(int vertex1, int vertex2) const;
  std::vector<int> GetVertices() const;
  std::vector<Edge> GetEdges() const;
  std::vector<Edge> GetIncomingEdges(int vertex) const;
  std::vector<Edge> GetOutgoingEdges(int vertex) const;
  int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;

 protected:
  std::set <int> vertices;
  std::map <int, std::vector<Edge>> inEdges, outEdges;
  std::map <int, int> index, outdex;
  int vertexNum = 0, edgeNum = 0;
};

#endif
