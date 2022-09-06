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
    bool prune(TreeNode* root)
    {
        if(root==NULL)
            return false;
        bool left = prune(root->left);
        bool right = prune(root->right);
        if(!left)
            root->left=NULL;
        if(!right)
            root->right=NULL;
        return root->val == 1 || left || right; 
    }
    TreeNode* pruneTree(TreeNode* root) {
       return prune(root)?root:NULL;
    }
};