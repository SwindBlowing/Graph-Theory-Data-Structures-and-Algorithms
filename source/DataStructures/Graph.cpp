#include <DataStructures/Graph.h>

Graph::Graph()
{
}

Graph::~Graph(){}

bool Graph::AddVertex(int vertex)
{
    if (ContainsVertex(vertex)) return 0;
    int nowId = ++totId;
    id.insert(std::pair<int, int> {vertex, nowId});
    inEdges.insert(std::pair<int, std::vector<Edge>> {nowId, {}});
    outEdges.insert(std::pair<int, std::vector<Edge>> {nowId, {}});
    name[nowId] = vertex;
    vertexNum++;
    return 1;
}

bool Graph::RemoveVertex(int vertex)
{
    std::map <int, int>::iterator it = id.find(vertex);
    if (!ContainsVertex(vertex)) return 0;
    int nowId = it->second;
    name[nowId] = 0;
    vertexNum--;
    auto it_in = inEdges.find(nowId);
    auto nex = it_in->second.begin(); nex++;
    for (auto t = it_in->second.begin(); t != it_in->second.end();)
    {
        RemoveEdge(t->GetSource(), t->GetDestination());
        t = nex;
        if (nex != it_in->second.end()) nex++;
    }
    auto it_out = outEdges.find(nowId);
    nex = it_out->second.begin(); nex++;
    std::cout << nex->GetSource() << ' ' << nex->GetDestination() << std::endl;
    for (auto t = it_out->second.begin(); t != it_out->second.end();)
    {
        RemoveEdge(t->GetSource(), t->GetDestination());
        t = nex;
        if (nex != it_out->second.end()) nex++;
    }
    id.erase(it);
    return 1;
}

bool Graph::AddEdge(int vertex1, int vertex2)
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || ContainsEdge(vertex1, vertex2))
        return 0;
    Edge e = Edge(vertex1, vertex2);
    auto it1 = id.find(vertex1);
    auto it2 = id.find(vertex2);
    int id1 = it1->second, id2 = it2->second;
    auto it_in = inEdges.find(id2);
    auto it_out = outEdges.find(id1);
    it_in->second.push_back(e);
    it_out->second.push_back(e);
    outdex[id1]++; index[id2]++;
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
    int id1 = it1->second, id2 = it2->second;
    auto it_in = inEdges.find(id2);
    auto it_out = outEdges.find(id1);
    std::vector<Edge>::iterator t;
    t = std::find(it_in->second.begin(), it_in->second.end(), e);
    it_in->second.erase(t);
    t = std::find(it_out->second.begin(), it_out->second.end(), e);
    assert(t != it_out->second.end());
    it_out->second.erase(t);
    outdex[id1]--; index[id2]--;
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
    return id.find(vertex) != id.end();
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2)) return 0;
    int id1 = id.find(vertex1)->second, id2 = id.find(vertex2)->second;
    auto it = outEdges.find(id1);
    return std::find(it->second.begin(), it->second.end(), Edge(vertex1, vertex2)) != it->second.end();
}

std::vector<int> Graph::GetVertices() const
{
    std::vector <int> vertices; vertices.clear();
    for (auto it = id.begin(); it != id.end(); it++)
        vertices.push_back(it->first);
    return vertices;
}

std::vector<Edge> Graph::GetEdges() const
{
    std::vector <Edge> edges; edges.clear();
    for (auto it = id.begin(); it != id.end(); it++) {
        int id = it->second;
        auto t = outEdges.find(id);
        for (auto now = t->second.begin(); now != t->second.end(); now++)
            edges.push_back(*now);
    }
    return edges;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    return inEdges.find(id.find(vertex)->second)->second;
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    return outEdges.find(id.find(vertex)->second)->second;
}

int Graph::GetDegree(int vertex) const
{
    if (!ContainsVertex(vertex)) return 0;
    return outdex[id.find(vertex)->second];
}

std::vector<int> Graph::GetNeighbors(int vertex) const
{
    if (!ContainsVertex(vertex)) return {};
    std::vector <int> neighbors; neighbors.clear();
    int nowId = id.find(vertex)->second;
    auto it = outEdges.find(nowId);
    for (auto t = it->second.begin(); t != it->second.end(); t++)
        neighbors.push_back(t->GetDestination());
    return neighbors;
}