#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "\nEnter the number of vertices:";
    int n, i, j;
    cin >> n;
    vector<int> adj[n];
    cout << "\nEnter the number of edges:";
    int m;
    cin >> m;
    vector<pair<int, int>> a;
    vector<int> u, v;
    cout << "Enter the edges as v1, v2, weight: \n";
    for (i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        u.push_back(x);
        v.push_back(y);
        a.push_back(make_pair(w, i));
    }
    cout << "Minimum spanning tree:\n";
    vector<bool> visited(n, false);
    visited[0] = true;
    for (i = 0; i < n - 1; i++)
    {
        int x, y, weight = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (visited[j])
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == k || visited[k])
                        continue;
                    for (int l = 0; l < m; l++)
                    {
                        if ((u[l] == k && v[l] == j) || (u[l] == j && v[l] == k))
                        {

                            if (a[l].first < weight)
                            {
                                x = k;
                                y = j;
                                weight = a[l].first;
                            }
                        }
                    }
                }
            }
        }
        visited[x] = true;
        visited[y] = true;
        cout << x + 1 << "-----" << y + 1 << " | Weight:" << weight << "\n";
    }
    return 0;
}