#include <iostream>
#include <climits>
using namespace std;
//Recursion
int steps(int x)
{
    if (x == 1)
        return 0;
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (x % 2 == 0)
        a = steps(x / 2);
    if (x % 3 == 0)
        b = steps(x / 3);
    c = steps(x - 1);
    return 1 + min(a, min(b, c));
}
//Top Down
int steps(int x, int dp[])
{
    if (x < 2)
        return 0;
    dp[2] = 1;
    dp[3] = 1;
    if (dp[x])
        return dp[x];
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (x % 2 == 0)
        a = steps(x / 2, dp);
    if (x % 3 == 0)
        b = steps(x / 3, dp);
    c = steps(x - 1, dp);
    dp[x] = 1 + min(a, min(b, c));
}
//Btoom Up
int stepsBU(int x)
{
    if (x < 2)
        return 0;
    int dp[x + 1];
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < x; i++)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i % 2 == 0)
            a = dp[i / 2];
        if (i % 3 == 0)
            b = dp[i / 3];
        c = dp[i - 1];
        dp[i] = 1 + min(a, min(b, c));
    }
    return dp[x];
}
int main()
{
    cout << steps(50) << endl;
    int dp[100] = {0};
    cout << steps(50, dp) << endl;
    cout << stepsBU(50);
}