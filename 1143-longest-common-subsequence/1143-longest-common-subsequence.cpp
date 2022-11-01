class Solution {
public:
    int dp[1005][10005];
    int LCSHelper(string &s1, string &s2, int i, int j) {
        if(i==s1.length() || j==s2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1+LCSHelper(s1, s2, i+1, j+1);
        return dp[i][j]=max(LCSHelper(s1, s2, i+1, j),LCSHelper(s1, s2, i, j+1));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        memset(dp, -1, sizeof(dp));
        return LCSHelper(s1, s2, 0, 0);
    }
};
