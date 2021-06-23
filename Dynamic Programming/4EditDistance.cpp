#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int t = min(dp[i - 1][j], dp[i][j - 1]);
                t = min(t, dp[i - 1][j - 1]);
                dp[i][j] = 1 + t;
            }
        }
    }
    return dp[m][n];
}
int main()
{
    cout << editDistance("Saturday", "Sunday");
}