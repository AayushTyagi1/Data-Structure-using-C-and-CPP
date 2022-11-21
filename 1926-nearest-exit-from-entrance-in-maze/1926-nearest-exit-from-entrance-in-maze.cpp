class Solution {
public:
        int dir[5]={0,1,0,-1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        vector<vector<bool>>vis(maze.size(),vector<bool>(maze[0].size(),0));
        queue<vector<int>>q;
        q.push({e[0],e[1],0});
        vis[e[0]][e[1]]=1;
        while(!q.empty()){
            vector<int>p=q.front();q.pop();
            for(int i =0;i<4;i++){
                int x=p[0]+dir[i],y=p[1]+dir[i+1];

                    if(x<0 || y<0 || x>=maze.size() ||  y>=maze[0].size() || maze[x][y]=='+')continue;
                    if((x==0 || y==0 || x==(maze.size()-1) ||  y==(maze[0].size()-1)) && maze[x][y]!='+' && !vis[x][y])return p[2]+1;
                    if( maze[x][y]!='+' && !vis[x][y])vis[x][y]=1,q.push({x,y,p[2]+1});
            }
            
        }
        return -1;
    }
};