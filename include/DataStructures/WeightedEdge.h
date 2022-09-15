#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

#include <DataStructures/Edge.h>

class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, int weight): Edge(source, destination), weight(weight) {}
   ~WeightedEdge() {}
  public:
   int GetWeight() const;
  private:
   int weight;
 };

#endif
