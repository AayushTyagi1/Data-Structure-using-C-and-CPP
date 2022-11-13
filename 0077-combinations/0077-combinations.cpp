class Solution {
    vector<vector<int>> ans;
public:
    void sol(int n, int k, vector<int> &cur, int ind)
    {
        if(k==0){
            ans.push_back(cur);
            return;}
        for(int i=ind;i<=n;i++)
        {
            cur.push_back(i);
            sol(n, k-1, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        sol(n, k, cur, 1);
        return ans;
    }
};