class Solution {
public:
    
    static bool comp(pair<int, int> &a, pair<int, int>& b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    }

    void solve(TreeNode* root, int row, int col,map<int,vector<pair<int,int>>>&mp)
    {
        if(root == NULL)
            return;

        mp[col].push_back({row, root -> val});
        solve(root -> left, row + 1, col - 1, mp);
        solve(root -> right, row + 1, col + 1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        solve(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto x : mp)
        {
            vector<pair<int, int>> arr = x.second;
            sort(arr.begin(), arr.end(), comp);
            vector<int> temp;
            
            for(int i = 0; i < arr.size(); i++)
            {
                temp.push_back(arr[i].second);
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};