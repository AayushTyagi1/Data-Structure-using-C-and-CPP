#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000
int dp[1000][1000];
int LCS(string s1, string s2, int m, int n)
{
    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0 || n == 0)
        dp[m][n] = 0;
    else
    {
        if (s1[m - 1] == s2[n - 1])
            dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);
        else
            dp[m][n] = max(LCS(s1, s2, m - 1, n), LCS(s1, s2, m, n - 1));
    }

    return dp[m][n];
}
int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int m = s1.size();
    int n = s2.size();
    memset(dp, -1, sizeof(dp));
    cout << LCS(s1, s2, m, n);
}