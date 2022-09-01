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
    int good(TreeNode* root, int maxVal)
    {
        if(root==NULL)
            return 0;
        int count=0;
        count+=root->val>=maxVal;
        maxVal = max(root->val, maxVal);
        count+=good(root->left, maxVal);
        count+=good(root->right, maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return good(root, root->val);
        
            
    }
};