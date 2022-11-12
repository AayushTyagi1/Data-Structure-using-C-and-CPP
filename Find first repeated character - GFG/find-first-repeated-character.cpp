//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

#include<climits>
string firstRepChar(string s)
{
    
    vector<int> count(32, -1);
    int rep=INT_MAX; string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]-'a']!=-1){
                ans=s[i];
                break;}
        count[s[i]-'a']++;
    }
    if(ans=="")
    return "-1";
    return ans;
}