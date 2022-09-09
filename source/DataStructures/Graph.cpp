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
    edges.insert(std::pair<int, std::vector<Edge>> {nowId, {}});
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
    std::map <int, std::vector<Edge>>::iterator it2 = edges.find(nowId);
    edgeNum -= it2->second.size();
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
    std::map <int, std::vector<Edge>>::iterator it = edges.find(id1);
    std::vector<Edge>::iterator t;
    //t = std::find(it->second.begin(), it->second.end(), e);
    for (t = it->second.begin(); t != it->second.end(); t++)
        if (t->GetDestination() == vertex2) return 0;
    //if (t != it->second.end()) return 0;
    it->second.push_back(e);
    outdex[id1]++; index[id2]++;
    edgeNum++;
    return 1;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    std::map <int, int>::iterator it1 = id.find(vertex1);
    std::map <int, int>::iterator it2 = id.find(vertex2);
    if (it1 == id.end() || it2 == id.end())
        return 0;
    int id1 = it1->second, id2 = it2->second;
    std::map <int, std::vector<Edge>>::iterator it = edges.find(id1);
    std::vector<Edge>::iterator t;
    //t = std::find(it->second.begin(), it->second.end(), Edge(vertex1, vertex2));
    //if (t == it->second.end()) return 0;
    for (t = it->second.begin(); t != it->second.end(); t++)
        if (t->GetDestination() == vertex2) {
            it->second.erase(t);
            outdex[id1]--; index[id2]--;
            edgeNum--;
            return 1;
        }
    return 0;
}