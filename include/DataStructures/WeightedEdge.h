#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

#include "Edge.h"

class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, int weight): Edge(source, destination), weight(weight) {}
  public:
   int GetWeight() const;
  private:
   int weight;
 };

#endif
