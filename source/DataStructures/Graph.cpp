#include <DataStructures/Graph.h>

Graph::Graph()
{
}

Graph::~Graph(){}

bool Graph::AddVertex(int vertex)
{
    if (ContainsVertex(vertex)) return 0;
    vertices.insert(vertex);
    inEdges.insert(std::pair<int, std::vector<Edge>> {vertex, {}});
    outEdges.insert(std::pair<int, std::vector<Edge>> {vertex, {}});
    vertexNum++;
    return 1;
}

bool Graph::RemoveVertex(int vertex)
{
    std::vector <Edge> Pause; Pause.clear();
    if (!ContainsVertex(vertex)) return 0;
    vertexNum--;
    auto it_in = inEdges.find(vertex);
    for (auto t = it_in->second.begin(); t != it_in->second.end(); t++)
        Pause.push_back(*t);
    for (auto t = Pause.begin(); t != Pause.end(); t++)
        RemoveEdge(t->GetSource(), t->GetDestination());
    Pause.clear();
    auto it_out = outEdges.find(vertex);
    for (auto t = it_out->second.begin(); t != it_out->second.end(); t++)
        Pause.push_back(*t);
    for (auto t = Pause.begin(); t != Pause.end(); t++)
        RemoveEdge(t->GetSource(), t->GetDestination());
    vertices.erase(vertex);
    return 1;
}

bool Graph::AddEdge(int vertex1, int vertex2)
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || ContainsEdge(vertex1, vertex2))
        return 0;
    Edge e = Edge(vertex1, vertex2);
    auto it_in = inEdges.find(vertex2);
    auto it_out = outEdges.find(vertex1);
    it_in->second.push_back(e);
    it_out->second.push_back(e);
    outdex[vertex1]++; index[vertex2]++;
    edgeNum++;
    return 1;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2))
        return 0;
    Edge e = Edge(vertex1, vertex2);
    auto it1 = id.find(vertex1);
    auto it2 = id.find(vertex2);
    auto it_in = inEdges.find(vertex2;
    auto it_out = outEdges.find(vertex1);
    std::vector<Edge>::iterator t;
    t = std::find(it_in->second.begin(), it_in->second.end(), e);
    it_in->second.erase(t);
    t = std::find(it_out->second.begin(), it_out->second.end(), e);
    assert(t != it_out->second.end());
    it_out->second.erase(t);
    outdex[vertex1]--; index[vertex2]--;
    edgeNum--;
    return 1;
}

int Graph::CountVertices() const
{
    return vertexNum;
}

int Graph::CountEdges() const
{
    return edgeNum;
}

bool Graph::ContainsVertex(int vertex) const
{
    return vertices.find(vertex) != vertices.end();
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2)) return 0;
    auto it = outEdges.find(vertex1);
    return std::find(it->second.begin(), it->second.end(), Edge(vertex1, vertex2)) != it->second.end();
}

std::vector<int> Graph::GetVertices() const
{
    std::vector <int> nowVertices; nowVertices.clear();
    for (auto it = vertices.begin(); it != vertices.end(); it++)
        nowVertices.push_back(*it);
    return nowVertices;
}

std::vector<Edge> Graph::GetEdges() const
{
    std::vector <Edge> edges; edges.clear();
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        auto t = outEdges.find(*it);
        for (auto now = t->second.begin(); now != t->second.end(); now++)
            edges.push_back(*now);
    }
    return edges;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    return inEdges.at(vertex);
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    return outEdges.at(vertex);
}

int Graph::GetDegree(int vertex) const
{
    if (!ContainsVertex(vertex)) return 0;
    return outdex.at(vertex);
}

std::vector<int> Graph::GetNeighbors(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    std::vector <int> neighbors; neighbors.clear();
    auto it = outEdges.find(vertex);
    for (auto t = it->second.begin(); t != it->second.end(); t++)
        neighbors.push_back(t->GetDestination());
    return neighbors;
}