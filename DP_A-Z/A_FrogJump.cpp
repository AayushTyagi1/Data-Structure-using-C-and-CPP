#include <iostream>
using namespace std;
int minCost(int heights[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            dp[i] = abs(heights[i] - heights[i - 1]);
        else
            dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[n];
}

/*
int minCost(int heights[], int n)
{
    if (n == 0)
        return 0;
    return min(abs(heights[n] - heights[n - 1]) + minCost(heights, n - 1), (n - 2 >= 0) ? (abs(heights[n] - heights[n - 2]) + minCost(heights, n - 2)) : 99999);
}
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minCost(arr, n - 1);
}