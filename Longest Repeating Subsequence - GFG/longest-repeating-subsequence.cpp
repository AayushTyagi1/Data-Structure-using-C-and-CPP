//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int LCS(string s1, int n)
	{
	    vector<vector<int>> dp(2, vector<int> (n+1, 0));
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(s1[i-1]==s1[j-1]&&i!=j)
	                dp[i&1][j]=dp[(i-1)&1][j-1]+1;
	           else
	                dp[i&1][j] = max(dp[(i-1)&1][j], dp[i&1][j-1]);
	        }
	    }
	    return dp[n&1][n];
	}
		int LongestRepeatingSubsequence(string str){
		    return LCS(str, str.length());
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends