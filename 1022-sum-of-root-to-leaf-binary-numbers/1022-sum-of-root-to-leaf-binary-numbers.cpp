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
    int ans = 0;
public:
    void preorder(TreeNode* root, int cur)
    {
        if(root)
        {
            //left shift the cur by 1 and then add 0/1 from root->val
            cur = (cur<<1) | root->val;
            if(root->left == NULL && root->right == NULL)
                ans+=cur;
            preorder(root->left, cur);
            preorder(root->right, cur);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
};