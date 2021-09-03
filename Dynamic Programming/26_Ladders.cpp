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
int main()
{
    int N, K;
    N = 4;
    K = 3;
    int dp[100] = {0};
    cout << ladder(N, K, dp);
}