#include <iostream>
using namespace std;
int ladder(int N, int K, int dp[])
{
    if (N == 0)
        return 1;

    if (dp[N] != 0)
        return dp[N];

    int noofways = 0;
    for (int i = 1; i <= K; i++)
    {
        if (N - i >= 0)
            noofways += ladder(N - i, K, dp);
    }
    return dp[N] = noofways;
}
int ladder(int n, int k)
{
    int dp[n + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}
int ladderO(int n, int k)
{
    int dp[n + 1] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= k)
            dp[i] = 2 * dp[i - 1];
        else
            dp[i] = 2 * dp[i - 1] - dp[n - k];
    }
    return dp[n];
}
int main()
{
    int N, K;
    N = 4;
    K = 3;
    int dp[100] = {0};
    cout << ladder(N, K, dp) << " " << ladderO(N, K);
}