class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0].push_back(1);
        for(int i=1;i<n;i++)
        {
            int num = ans[i-1].size();
            ans[i].push_back(ans[i-1][0]);
            for(int j=0;j<num-1;j++)
            {
                if(j>=0 && j+1<num)
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            ans[i].push_back(ans[i-1][0]);
        }
        
        return ans;
    }
};