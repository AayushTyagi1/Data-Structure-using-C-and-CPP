class Solution {
public:
    
    void help(vector<vector<int>>& arr,int x,int y,int**v)
    {
        if(x>=arr.size()||x<0||y>=arr[0].size()||y<0||v[x][y]==1)
        {
            return;
        }
        v[x][y]=1;
        if(x-1>=0 && arr[x-1][y]>=arr[x][y])
        {
            help(arr,x-1,y,v);
        }
        if(y-1>=0 && arr[x][y-1]>=arr[x][y])
        {
            help(arr,x,y-1,v);
        }
        if(x+1<arr.size() && arr[x+1][y]>=arr[x][y])
        {
            help(arr,x+1,y,v);
        }
        if(y+1<arr[0].size() && arr[x][y+1]>=arr[x][y])
        {
            help(arr,x,y+1,v);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int**v1=new int*[arr.size()],**v2=new int*[arr.size()];
        for(int i=0;i<arr.size();i++)
        {
            v1[i]=new int[arr[0].size()];
            v2[i]=new int[arr[0].size()];
            for(int j=0;j<arr[0].size();j++)
            {
                v1[i][j]=0;
                v2[i][j]=0;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            help(arr,i,0,v1);
            help(arr,i,arr[0].size()-1,v2);
        }
        for(int i=0;i<arr[0].size();i++)
        {
            help(arr,0,i,v1);
            help(arr,arr.size()-1,i,v2);
        }
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(v1[i][j]&&v2[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};