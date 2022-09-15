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
    index.insert(std::pair<int, int>{vertex, 0});
    outdex.insert(std::pair<int, int>{vertex, 0});
    vertexNum++;
    return 1;
}

bool Graph::RemoveVertex(int vertex)
{
    std::vector <Edge> Pause; Pause.clear();
    if (!ContainsVertex(vertex)) return 0;
    vertexNum--;
    auto it_in = inEdges.at(vertex);
    for (auto t = it_in.begin(); t != it_in.end(); t++)
        Pause.push_back(*t);
    for (auto t = Pause.begin(); t != Pause.end(); t++)
        RemoveEdge(t->GetSource(), t->GetDestination());
    Pause.clear();
    auto it_out = outEdges.at(vertex);
    for (auto t = it_out.begin(); t != it_out.end(); t++)
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
    auto it_in = inEdges.at(vertex2);
    auto it_out = outEdges.at(vertex1);
    it_in.push_back(e);
    it_out.push_back(e);
    outdex[vertex1]++; index[vertex2]++;
    edgeNum++;
    return 1;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2))
        return 0;
    Edge e = Edge(vertex1, vertex2);
    auto it_in = inEdges.at(vertex2);
    auto it_out = outEdges.at(vertex1);
    std::vector<Edge>::iterator t;
    t = std::find(it_in.begin(), it_in.end(), e);
    it_in.erase(t);
    t = std::find(it_out.begin(), it_out.end(), e);
    assert(t != it_out.end());
    it_out.erase(t);
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
    auto it = outEdges.at(vertex1);
    return std::find(it.begin(), it.end(), Edge(vertex1, vertex2)) != it.end();
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
        auto t = outEdges.at(*it);
        for (auto now = t.begin(); now != t.end(); now++)
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
    auto it = outEdges.at(vertex);
    for (auto t = it.begin(); t != it.end(); t++)
        neighbors.push_back(t->GetDestination());
    return neighbors;
}