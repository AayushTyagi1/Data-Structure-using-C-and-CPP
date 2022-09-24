class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		if(trust.empty() && n==1)
            return 1;
		vector<int> degree(n+1,0);
		for(auto edge : trust){
            degree[edge[0]]=INT_MIN;
            degree[edge[1]]++;
        }
		
		for(int i=0;i<=n;i++){
            if(degree[i]==n-1)
                return i;
        }
        return -1;
    }
};