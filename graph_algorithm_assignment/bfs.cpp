#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add_edge(int a, int b, vector<int> *adj)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void bfs(vector<int> *adj, int v)
{
    map<int, string> status;
    for (int k = 0; k < v; k++)
        status[k] = "NV";
    int *final_list = new int[v];
    int temp1 = 0, val, v_count;
    queue<int> q;
    while (1)
    {
        v_count = v;
        for (auto tmp = status.begin(); tmp != status.end(); tmp++)
        {
            if (tmp->second == "NV")
            {
                q.push(tmp->first);
                break;
            }
            v_count--;
        }
        if (v_count == 0)
            break;

        while (!q.empty())
        {
            val = q.front();
            q.pop();
            if (status[val] == "NV")
            {
                status[val] = "V";
                final_list[temp1] = val;
                temp1++;
                for (auto tmp = adj[val].begin(); tmp != adj[val].end(); tmp++)
                {
                    if (status[*tmp] == "NV")
                        q.push(*tmp);
                }
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout << final_list[i] << " ";
}

int main()
{
    int v, e, i;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << " Enter the number of edges: ";
    cin >> e;
    vector<int> *adj = new vector<int>[e];
    int a, b;
    for (i = 0; i < e; i++)
    {
        cin >> a >> b;
        add_edge(a, b, adj);
    }
    bfs(adj, v);
    delete[] adj;
    return 0;
}
