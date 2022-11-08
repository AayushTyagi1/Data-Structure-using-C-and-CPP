class Solution {
public:
    int LCS(string s1, string s2, int m, int n)
    {
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i&1][j]=dp[(i-1)&1][j-1]+1;
                else
                    dp[i&1][j] = max(dp[(i-1)&1][j], dp[i&1][j-1]);
            }
        }
        return dp[m&1][n];
    }
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return LCS(s1, s2, s1.length(), s2.length());
    }
};