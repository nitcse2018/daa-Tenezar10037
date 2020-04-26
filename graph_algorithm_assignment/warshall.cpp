#include <bits/stdc++.h>
using namespace std;
#define V 4

void print(int dist[][V])
{
    cout << "Shortest Distance matrix: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void fWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        }
    }

    print(dist);
}

int main()
{
    int graph[V][V], i, j;

    cout << "Enter the adjacency matrix. Enter -1 if no edge\n";
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] = -1)
                graph[i][j] = INT_MAX;
        }
    fWarshall(graph);
    return 0;
}