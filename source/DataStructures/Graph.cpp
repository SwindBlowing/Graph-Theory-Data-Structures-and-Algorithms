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
    if (id.find(vertex) == id.end()) return 0;
    std::map <int, int>::iterator it = id.find(vertex);
    int nowId = it->second;
    name[nowId] = 0;
    vertexNum--;
    std::map <int, std::vector<Edge>>::iterator it2 = edges.find(vertex);
    edgeNum -= it2->second.size();
    id.erase(it);
    return 1;
}

bool Graph::AddEdge(int vertex1, int vertex2)
{
    if (id.find(vertex1) == id.end() || id.find(vertex2) == id.end())
        return 0;
    std::map <int, std::vector<Edge>>::iterator it = edges.find(vertex1);
    std::vector<Edge>::iterator t ;//= std::find(it->second.begin(), it->second.end(), Edge(vertex1, vertex2));
    /*if (t != it->second.end()) return 0;
    it->second.push_back(Edge(vertex1, vertex2));
    outdex[vertex1]++; index[vertex2]++;
    edgeNum++;
    return 1;*/
}
/*
bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    if (id.find(vertex1) == id.end() || id.find(vertex2) == id.end())
        return 0;
    std::map <int, std::vector<Edge>>::iterator it = edges.find(vertex1);
    std::vector<Edge>::iterator t = std::find(it->second.begin(), it->second.end(), vertex2);
    if (t == it->second.end()) return 0;
    it->second.erase(t);
    outdex[vertex1]--; index[vertex1]++;
    edgeNum--;
    return 1;
}*/