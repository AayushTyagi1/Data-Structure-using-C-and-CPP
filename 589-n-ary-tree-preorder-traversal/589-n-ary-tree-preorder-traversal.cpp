/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
public:
    void preorderH(Node *root)
    {
        if(root==NULL)
            return;
        ans.push_back(root->val);
        for(Node *c: root->children)
            preorder(c);
    }
    vector<int> preorder(Node* root) {
        preorderH(root);
        return ans;
    }
};