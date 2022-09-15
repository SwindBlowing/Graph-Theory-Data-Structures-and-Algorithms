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