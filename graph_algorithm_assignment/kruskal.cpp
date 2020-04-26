#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    cout << "\nEnter the number of vertices:";
    cin >> n;
    vector<int> adj[n];
    cout << "\nEnter the number of edges:";
    cin >> m;
    vector<pair<int, int>> a;
    vector<int> u, v;
    cout << "Enter edges as v1, v2, weight: " << endl;
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
    cout << "\nMinimum spanning tree:\n";
    sort(a.begin(), a.end());
    i = 0;
    vector<bool> visited(n, false);
    while (1)
    {
        if (i == n - 1)
            break;
        int x, y;
        x = u[a[i].second];
        y = v[a[i].second];
        while (visited[x] && visited[y])
        {
            i++;
            x = u[a[i].second];
            y = v[a[i].second];
        }
        visited[x] = true;
        visited[y] = true;
        cout << x + 1 << "-----" << y + 1 << " | Weight:" << a[i].first << "\n";
    }
    return 0;
}