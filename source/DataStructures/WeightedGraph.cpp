#include <DataStructures/WeightedGraph.h>

bool WeightedGraph::AddVertex(int vertex)
{
    if (!Graph::AddVertex(vertex)) return 0;
    inEdges.insert(std::pair<int, std::vector<WeightedEdge>> {vertex, {}});
    outEdges.insert(std::pair<int, std::vector<WeightedEdge>> {vertex, {}});
    return 1;
}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight)
{
    if (!Graph::AddEdge(vertex1, vertex2)) return 0;
    WeightedEdge e = WeightedEdge(vertex1, vertex2, weight);
    auto it_in = inEdges.find(vertex2);
    auto it_out = outEdges.find(vertex1);
    it_in->second.push_back(e);
    it_out->second.push_back(e);
    return 1;
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2))
        return 0;
    auto it_out = outEdges.at(vertex1);
    auto t = std::find(it_out.begin(), it_out.end(), (WeightedEdge){vertex1, vertex2, 0});
    if (t == it_out.end()) return 0;
    return t->GetWeight();
}

std::vector<WeightedEdge> WeightedGraph::GetEdges() const 
{
    std::vector <WeightedEdge> edges; edges.clear();
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        auto t = outEdges.find(*it);
        for (auto now = t->second.begin(); now != t->second.end(); now++)
            edges.push_back(*now);
    }
    return edges;
}

std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const 
{
    if (!ContainsVertex(vertex)) return {};
    return inEdges.at(vertex);
}

std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const 
{
    if (!ContainsVertex(vertex)) return {};
    return outEdges.at(vertex);
}