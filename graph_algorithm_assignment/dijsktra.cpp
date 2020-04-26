#include <iostream>
using namespace std;
#define V 9 //Number of vertices

void print(int dist[])
{
    cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int getMin(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (dist[v] <= min && !sptSet[v])
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijsktra(int graph[][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = getMin(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
                dist[v] = dist[u] + graph[u][v];
    }
    print(dist);
}

int main()
{
    int graph[V][V];
    cout << "Enter the adjacency matrix for " << V << " vertices: \n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    dijsktra(graph, src);
    return 0;
}