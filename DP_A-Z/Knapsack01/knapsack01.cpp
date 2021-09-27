#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> dp;
int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    if (W == 0 || n == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(wt, val, W, n - 1);
    return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
}

int knapsackBU(vector<int> &wt, vector<int> &val, int W, int n)
{
    if (W == 0 || n == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
        return knapsackBU(wt, val, W, n - 1);
    return max(val[n - 1] + knapsackBU(wt, val, W - wt[n - 1], n - 1), knapsackBU(wt, val, W, n - 1));
}
int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 7, 5};
    int W = 7;
    cout << knapsack(wt, val, W, 4) << endl;
    dp.resize(5, vector<int>(W + 1, -1));
    cout << knapsackBU(wt, val, 7, 4);
}