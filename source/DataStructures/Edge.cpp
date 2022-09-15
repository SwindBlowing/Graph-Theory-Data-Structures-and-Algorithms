#include <DataStructures/Edge.h>

Edge::Edge(int source, int destination)
{
    this->source = source;
    this->destination = destination;
}

Edge::~Edge(){}

int Edge::GetSource() const {
    return this->source;
}

int Edge::GetDestination() const {
    return this->destination;
}

bool Edge::operator ==(const Edge &a) const
{
    return this->source == a.source && this->destination == a.destination;
}

bool Edge::operator <(const Edge &a) const
{
    return (this->source == a.source) ? this->source < a.source : this->destination < a.destination;
}