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
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool isLeft = true) {
        if ( d == 1 )
        {
            TreeNode *left = isLeft? root : NULL, *right = isLeft? NULL : root;
            return new TreeNode(v, left, right);
        }
            
        if ( root )
        {
            root->left = addOneRow(root->left, v, d - 1, true);
            root->right = addOneRow(root->right, v, d - 1, false);
        }
            
        return root;
    }
};