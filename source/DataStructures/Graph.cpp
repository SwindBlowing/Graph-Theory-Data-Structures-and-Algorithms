#include <DataStructures/Graph.h>

Graph::Graph()
{
}

Graph::~Graph(){}

bool Graph::AddVertex(int vertex)
{
    if (id.find(vertex) != id.end()) return 0;
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
    if (it == id.end()) return 0;
    int nowId = it->second;
    name[nowId] = 0;
    vertexNum--;
    std::map <int, std::vector<Edge>>::iterator it_in = inEdges.find(nowId);
    std::vector<Edge>::iterator nex = it_in->second.begin(); nex++;
    for (std::vector<Edge>::iterator t = it_in->second.begin(); t != it_in->second.end();)
    {
        RemoveEdge(t->GetSource(), t->GetDestination());
        t = nex;
        if (nex != it_in->second.end()) nex++;
    }
    id.erase(it);
    return 1;
}

bool Graph::AddEdge(int vertex1, int vertex2)
{
    Edge e = Edge(vertex1, vertex2);
    std::map <int, int>::iterator it1 = id.find(vertex1);
    std::map <int, int>::iterator it2 = id.find(vertex2);
    if (it1 == id.end() || it2 == id.end())
        return 0;
    int id1 = it1->second, id2 = it2->second;
    std::map <int, std::vector<Edge>>::iterator it_in = inEdges.find(id2);
    std::map <int, std::vector<Edge>>::iterator it_out = outEdges.find(id1);
    std::vector<Edge>::iterator t = std::find(it_in->second.begin(), it_in->second.end(), e);
    if (t != it_in->second.end()) return 0;
    it_in->second.push_back(e);
    it_out->second.push_back(e);
    outdex[id1]++; index[id2]++;
    edgeNum++;
    return 1;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    Edge e = Edge(vertex1, vertex2);
    std::map <int, int>::iterator it1 = id.find(vertex1);
    std::map <int, int>::iterator it2 = id.find(vertex2);
    if (it1 == id.end() || it2 == id.end())
        return 0;
    int id1 = it1->second, id2 = it2->second;
    std::map <int, std::vector<Edge>>::iterator it_in = inEdges.find(id2);
    std::map <int, std::vector<Edge>>::iterator it_out = outEdges.find(id1);
    std::vector<Edge>::iterator t;
    t = std::find(it_in->second.begin(), it_in->second.end(), e);
    if (t == it_in->second.end()) return 0;
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
    //return std::find(edges.begin(), edges.end(), Edge(vertex1, vertex2)) != edges.end(); 
    if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2)) return 0;
    int id1 = id.find(vertex1)->second, id2 = id.find(vertex2)->second;
    auto it = outEdges.find(id1);
    return std::find(it->second.begin(), it->second.end(), Edge(vertex1, vertex2)) != it->second.end();
}

std::vector<int> Graph::GetVertices() const
{
    //return vertices;
    std::vector <int> vertices; vertices.clear();
    for (auto it = id.begin(); it != id.end(); it++)
        vertices.push_back(it->first);
    return vertices;
}

std::vector<Edge> Graph::GetEdges() const
{
    //return edges;
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