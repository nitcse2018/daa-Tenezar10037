#include <bits/stdc++.h>
using namespace std;
#define n 4

int path[n + 1];
bool visited[n];
int minCost = INT_MAX;

void storeToPath(int curr_path[])
{
    for (int i = 0; i < n; i++)
        path[i] = curr_path[i];
    path[n] = curr_path[0];
}

int firstMin(int adj[n][n], int i)
{
    int min = INT_MAX, j;
    for (j = 0; j < n; j++)
        if (adj[i][j] < min && i != j)
            min = adj[i][j];
    return min;
}

int secondMin(int adj[n][n], int i)
{
    int first = INT_MAX, second = INT_MAX, j;
    for (j = 0; j < n; j++)
    {
        if (i == j)
            continue;
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void TSPRec(int adj[n][n], int curr_bound, int curr_cost, int lvl, int curr_path[])
{
    if (lvl == n)
    {
        if (adj[curr_path[lvl - 1]][curr_path[0]] != 0)
        {
            int currCost = curr_cost + adj[curr_path[lvl - 1]][curr_path[0]];
            if (currCost < minCost)
            {
                storeToPath(curr_path);
                minCost = currCost;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (adj[curr_path[lvl - 1]][i] != 0 && !visited[i])
        {
            int temp = curr_bound;
            curr_cost += adj[curr_path[lvl - 1]][i];

            if (lvl == 1)
                curr_bound -= (firstMin(adj, curr_path[lvl - 1]) + firstMin(adj, i)) / 2;
            else
                curr_bound -= (secondMin(adj, curr_path[lvl - 1]) + firstMin(adj, i)) / 2;

            if (curr_bound + curr_cost < minCost)
            {
                curr_path[lvl] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_cost, lvl + 1, curr_path);
            }

            curr_cost -= adj[curr_path[lvl - 1]][i];
            curr_bound = temp;

            memset(visited, false, sizeof(visited));
            for (int j = 0; j < lvl; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP(int adj[n][n])
{
    int curr_path[n + 1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
    for (int i = 0; i < n; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));
    curr_bound = (curr_bound & 1) ? (curr_bound / 2 + 1) : (curr_bound / 2);

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(adj, curr_bound, 0, 1, curr_path);
}

int main()
{
    int i;
    int adj[n][n] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    TSP(adj);

    cout << "Minimum Cost = " << minCost << endl;
    cout << "Path: ";
    for (i = 0; i <= n; i++)
        cout << path[i] << ' ';
    cout << endl;
    return 0;
}