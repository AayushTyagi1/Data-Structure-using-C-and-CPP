#include <iostream>
#include <climits>
using namespace std;

int minCost(int heights[], int n, int k)
{
    if (n == 0)
        return 0;
    mini = INT_MAX;
    for (int i = 0; i < min(k, n); i++)
    {
        mini = min(abs(heights[i] - heights[i+1]) + minCost(heights, n - 10)
    }
    return min(abs(heights[n] - heights[n - 1]) + minCost(heights, n - 1), (n - 2 >= 0) ? (abs(heights[n] - heights[n - 2]) + minCost(heights, n - 2)) : 99999);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minCost(arr, n - 1, 3);
}