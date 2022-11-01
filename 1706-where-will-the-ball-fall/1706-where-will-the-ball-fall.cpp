class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        if (m==1)
            return {-1};

        vector<int> curr(m,-1),next(m,-1);
        
        for (int i=0; i<m; i++)
        {
            curr[i]=i;
        }

        for (int i=0; i<n; i++)
        {

            if (grid[i][0]==1 && grid[i][1]==1)
            {
                next[1]=curr[0];
            }
            
            if (grid[i][0]==-1 && grid[i][1]==-1)
            {
                next[0]=curr[1];
            }
            
            for (int j=1; j<m-1; j++)
            {
                if (grid[i][j]==1 && grid[i][j+1]==1)
                {
                    next[j+1]=curr[j];
                }
                
                if (grid[i][j]==-1 && grid[i][j+1]==-1)
                {
                    next[j]=curr[j+1];
                }
            }

            curr = next;
            if (i==n-1)
                break;

            for (int i=0; i<m; i++)
            {
                next[i]=-1;
            }
        }
        vector <int> ans (m,-1);
        
        for (int i=0; i<m; i++)
        {
            if (next[i]!=-1)
                ans[next[i]]=i;
        }
        return ans;
    }
};