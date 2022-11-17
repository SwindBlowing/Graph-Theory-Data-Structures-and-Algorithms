#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <vector>
#include <map>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#define MAXN 1005

class UndirectedGraph : public Graph {
 public:
  UndirectedGraph() {selfLoop.clear();}
  ~UndirectedGraph() {selfLoop.clear();}
 public:
  //bool AddVertex(int vertex);
  //bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2) override;
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