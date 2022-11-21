class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int m, int n, bool &isCorner)
    {
        if(x<0 || y<0 || x==m || y==n || grid[x][y]==0 || visited[x][y])
            return 0;
        visited[x][y]=true;
        if(x==0 || y==0 || x==m-1 || y==n-1)
            if(grid[x][y]==1)
                isCorner=true;
        int area =1;
        area+=dfs(grid, visited, x+1, y, m, n, isCorner);
        area+=dfs(grid, visited, x, y+1, m, n, isCorner);
        area+=dfs(grid, visited, x-1, y, m, n, isCorner);
        area+=dfs(grid, visited, x, y-1, m, n, isCorner);
        return area;
    }
            
            
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int numOfEnclaves=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==false)
                {
                    bool isCorner = false;
                    int size = dfs(grid, visited, i, j, m, n, isCorner);
                    if(!isCorner)
                        numOfEnclaves+=size;
                }
            }
        }
        return numOfEnclaves;
    }
};