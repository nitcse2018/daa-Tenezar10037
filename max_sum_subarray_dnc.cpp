#include <iostream>
using namespace std;

int getMax(int x, int y, int z)
{
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

int combinedSum(int arr[], int l, int m, int h)
{
    int sum = 0, i;
    int lsum = INT_MIN, rsum = INT_MIN;
    for (i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > lsum)
            lsum = sum;
    }

    sum = 0;
    for (i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if (sum > rsum)
            rsum = sum;
    }

    return lsum + rsum;
}

int getMaxSum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return getMax(getMaxSum(arr, l, m), getMaxSum(arr, m + 1, h), combinedSum(arr, l, m, h));
}

int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Maximum sum = " << getMaxSum(arr, 0, n - 1) << endl;
    return 0;
}