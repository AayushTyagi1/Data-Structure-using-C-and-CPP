class Solution {
public:
    void dfs(vector<vector<int>>&stones,int ind,vector<bool>&visited,int n){
        visited[ind]=true;
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && (stones[ind][0]==stones[i][0 ] || stones[ind][1]==stones[i][1]))
            {
                dfs(stones, i, visited, n);
            }
        }
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int numberOfGroups=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(stones, i, visited, n);
                numberOfGroups++;
            }
        }
        return n - numberOfGroups;
    }
};