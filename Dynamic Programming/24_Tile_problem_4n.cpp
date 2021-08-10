#include <iostream>
using namespace std;
int countWays(int n)
{
    if (n < 1)
        return 0;
    if (n < 4)
        return 1;
    if (n == 4)
        return 2;
    return countWays(n - 1) + countWays(n - 4);
}
//Dynamic Programming
int countWaysBU(int n)
{
    if (n < 4)
        return 1;
    int dp[n + 1] = {0};
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= n; i++)
    {
        dp[i] = dp[i - 4] + dp[i - 1];
    }
    return dp[n];
}

int main()
{
    int n;
    n = 26;
    cout << countWays(n) << endl;
    cout << countWaysBU(n);
}