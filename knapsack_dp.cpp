#include <iostream>
using namespace std;

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int knapSack(int wn, int wt[], int val[], int n)
{
    int i, w;
    int ks[n + 1][wn + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= wn; w++)
        {
            if (i == 0 || w == 0)
                ks[i][w] = 0;
            else if (wt[i - 1] <= w)
                ks[i][w] = max(val[i - 1] + ks[i - 1][w - wt[i - 1]], ks[i - 1][w]);
            else
                ks[i][w] = ks[i - 1][w];
        }
    }

    return ks[n][wn];
}

int main()
{
    int n, i;
    cout << "Enter n: ";
    cin >> n;
    int val[n], wt[n], wn;
    for (i = 0; i < n; i++)
        cin >> val[i];
    for (i = 0; i < n; i++)
        cin >> wt[i];
    cin >> wn;
    int ks = knapSack(wn, wt, val, n);
    cout << ks << endl;
    return 0;
}