class Solution {
public:
    bool static comp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
        
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++)
        {
            int j;
            for(j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]!=1)
                    break;
            }
            v.push_back({j, i});
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        return ans;
    }
};