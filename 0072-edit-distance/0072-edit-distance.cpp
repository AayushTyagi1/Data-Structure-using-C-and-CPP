class Solution {
public:
    int LCS(string &w1, string &w2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
       for(int i=0;i<=m;i++)
       {
           for(int j=0;j<=n;j++)
           {
               if(i==0)
                   dp[i][j]=j;
               else if(j==0)
                   dp[i][j]=i;
               else if(w1[i-1]==w2[j-1])
                   dp[i][j]=dp[i-1][j-1];
               else dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
           }
       }
        return dp[m][n];
    }    
    int minDistance(string word1, string word2) {
        return LCS(word1, word2, word1.size(), word2.size());
    }
};
