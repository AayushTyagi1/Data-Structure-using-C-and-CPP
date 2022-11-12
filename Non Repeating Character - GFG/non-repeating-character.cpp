//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        vector<int> FI(27, -1);
       for(int i=0;i<S.length();i++)
       {
           if(FI[S[i]-'a']==-1)
                FI[S[i]-'a']=i;
            else
            FI[S[i]-'a']=-2;
       }
       int ind=INT_MAX;
       for(int i=0;i<=26;i++)
       {
           if(FI[i]>=0)
                ind=min(ind, FI[i]);
       }
       return (ind==INT_MAX)?'$':S[ind];
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends