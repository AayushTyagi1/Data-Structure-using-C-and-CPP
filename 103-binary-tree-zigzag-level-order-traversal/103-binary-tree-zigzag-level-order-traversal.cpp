/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *> q;
        int toggle=true;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *aux = q.front();
                q.pop();
                v.push_back(aux->val);
                if(aux->left)
                    q.push(aux->left);
                if(aux->right)
                    q.push(aux->right);
                
            }
            if(toggle)
                ans.push_back(v);
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            toggle=!toggle;
        }
        return ans;
    }
};