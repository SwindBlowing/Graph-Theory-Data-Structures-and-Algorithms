#include <DataStructures/Edge.h>
#include <assert.h>
#include <iostream>

int main()
{
    Edge e = Edge(1, 2);
    assert(e.GetDestination());
    assert(e.GetSource());
    std::cout << "succeeded!";
}