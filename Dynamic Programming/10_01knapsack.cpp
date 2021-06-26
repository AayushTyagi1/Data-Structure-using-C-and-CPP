#include <iostream>
using namespace std;
int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int v[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    cout << knapsack(10, wt, v, 4);
}