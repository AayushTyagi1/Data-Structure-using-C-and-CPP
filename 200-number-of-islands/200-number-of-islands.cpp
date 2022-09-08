class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int  m)
    {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1>=0 && row+1<n && grid[row+1][col]=='1' && vis[row+1][col]!=1)
            {
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(col+1>=0 && col+1<m && grid[row][col+1]=='1' && vis[row][col+1]!=1)
            {
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
            if(row-1>=0 && row-1<n && grid[row-1][col]=='1' && vis[row-1][col]!=1)
            {
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(col-1>=0 && col-1<m && grid[row][col-1]=='1' && vis[row][col-1]!=1)
            {
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
                
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=1 && grid[i][j]=='1')
                {
                   count++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return count;
    }
};