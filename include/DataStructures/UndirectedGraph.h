#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#define MAXN 1005

class UndirectedGraph : public Graph {
 public:
  UndirectedGraph() {};
  ~UndirectedGraph() {};
 public:
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  virtual bool AddEdge(int vertex1, int vertex2) override;
  virtual bool RemoveEdge(int vertex1, int vertex2) override;
 public:
  //int CountVertices() const;
  virtual int CountEdges() const override;
  //bool ContainsVertex(int vertex) const;
  //bool ContainsEdge(int vertex1, int vertex2) const;
  //std::vector<int> GetVertices() const;
  virtual std::vector<Edge> GetEdges() const override;
  //std::vector<Edge> GetIncomingEdges(int vertex) const;
  //std::vector<Edge> GetOutgoingEdges(int vertex) const;
  //int GetDegree(int vertex) const;
  //std::vector<int> GetNeighbors(int vertex) const;
 private:
  std::map <Edge, int> visited;
};

#endif