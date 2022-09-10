#include <DataStructures/Graph.h>

Graph::Graph()
{
    //for (int i = 0; i < MAXN; i++) nexFreePoint[i] = i + 1;
}

Graph::~Graph(){}

bool Graph::AddVertex(int vertex)
{
    if (id.find(vertex) != id.end()) return 0;
    int nowId = ++totId;
    //nexFreePoint[0] = nexFreePoint[nowId];
    id.insert(std::pair<int, int> {vertex, nowId});
    inEdges.insert(std::pair<int, std::vector<Edge>> {nowId, {}});
    outEdges.insert(std::pair<int, std::vector<Edge>> {nowId, {}});
    name[nowId] = vertex;
    vertexNum++;
    vertices.push_back(vertex);
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
    edgeNum -= it_in->second.size();
    std::map <int, std::vector<Edge>>::iterator it_out = inEdges.find(nowId);
    edgeNum -= it_out->second.size();
    id.erase(it);
    for (std::vector<int>::iterator t = vertices.begin(); t != vertices.end(); t++)
        if (*t == vertex) {
            vertices.erase(t);
            break;
        }
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
    //for (t = it->second.begin(); t != it->second.end(); t++)
    //    if (t->GetDestination() == vertex2) return 0;
    if (t != it_in->second.end()) return 0;
    it_in->second.push_back(e);
    it_out->second.push_back(e);
    outdex[id1]++; index[id2]++;
    edgeNum++;
    edges.push_back(e);
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
    std::map <int, std::vector<Edge>>::iterator it_out = inEdges.find(id1);
    std::vector<Edge>::iterator t;
    t = std::find(it_in->second.begin(), it_in->second.end(), Edge(vertex1, vertex2));
    if (t == it_in->second.end()) return 0;
    /*for (t = it->second.begin(); t != it->second.end(); t++)
        if (t->GetDestination() == vertex2) {
            it->second.erase(t);
            outdex[id1]--; index[id2]--;
            edgeNum--;
            for (std::vector<Edge>::iterator t2 = allEdges.begin(); t2 != allEdges.end(); t2++)
                if (*t2 == e) {
                    allEdges.erase(t2);
                    break;
                }
            return 1;
        }*/
    it_in->second.erase(t);
    t = std::find(it_out->second.begin(), it_out->second.end(), Edge(vertex1, vertex2));
    it_out->second.erase(t);
    outdex[id1]--; index[id2]--;
    edgeNum--;
    for (std::vector<Edge>::iterator t2 = edges.begin(); t2 != edges.end(); t2++)
        if (*t2 == e) {
            edges.erase(t2);
            break;
        }
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
    return std::find(edges.begin(), edges.end(), Edge(vertex1, vertex2)) != edges.end(); 
}

std::vector<int> Graph::GetVertices() const
{
    return vertices;
}

std::vector<Edge> Graph::GetEdges() const
{
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
    std::cout << id.find(vertex)->second;
    return outdex[id.find(vertex)->second];
}