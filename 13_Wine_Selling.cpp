#include <bits/stdc++.h>
using namespace std;
//Recursive
int maxProfit(int arr[], int i, int n, int y)
{
    if (i > n)
        return 0;
    return max(y * arr[i] + maxProfit(arr, i + 1, n, y + 1), y * arr[n] + maxProfit(arr, i, n - 1, y + 1));
}
//DP Top Down

int maxProfit(int arr[], int i, int j, int y, vector<vector<int>> dp)
{
    if (i > j)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    return dp[i][j] = max(y * arr[i] + maxProfit(arr, i + 1, j, y + 1, dp), y * arr[j] + maxProfit(arr, i, j - 1, y + 1, dp));
}
int main()
{
    int price[] = {2, 4, 6, 2, 5};
    int n = sizeof(price) / sizeof(price[0]);
    int ans = maxProfit(price, 0, n - 1, 1);
    cout << "Maximum profit = " << ans << endl;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    ans = maxProfit(price, 0, n - 1, 1, dp);
    cout << "Maximum profit = " << ans << endl;
    return 0;
}