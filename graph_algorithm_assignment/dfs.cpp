#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

int main()
{
    int v, e, i;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << " Enter the number of edges: ";
    cin >> e;
    int a, b, s;
    Graph g(v);
    for (i = 0; i < e; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cout << "Enter the start vertex: ";
    cin >> s;
    g.DFS(s);
    return 0;
}