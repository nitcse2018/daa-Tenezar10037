#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int dline;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void scheduleJob(Job arr[], int n)
{
    sort(arr, arr + n, comparison);
    int result[n];
    bool tslot[n];
    int i, j;
    for (i = 0; i < n; i++)
        tslot[i] = false;
    for (i = 0; i < n; i++)
    {
        for (j = min(n, arr[i].dline) - 1; j >= 0; j--)
        {
            if (tslot[j] == false)
            {
                result[j] = i;
                tslot[j] = true;
                break;
            }
        }
    }

    int tprofit = 0;
    cout << "Job Sequence: ";
    for (i = 0; i < n; i++)
    {
        if (tslot[i] == true)
        {
            cout << arr[result[i]].id << " ";
            tprofit += arr[result[i]].profit;
        }
    }
    cout << "\nTotal profit = " << tprofit << endl;
}

int main()
{
    Job arr[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}};
    int n = 5;
    scheduleJob(arr, n);
    return 0;
}