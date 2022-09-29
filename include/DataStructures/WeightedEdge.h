#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

#include <DataStructures/Edge.h>

template <typename T>
class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, T weight): Edge(source, destination), weight(weight) {}
   ~WeightedEdge() {}
  public:
   T GetWeight() const;
  private:
   T weight;
 };

#endif
