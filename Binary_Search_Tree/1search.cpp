#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        val = k;
        left = right = NULL;
    }
};

bool search(Node *root, int n)
{
    if (root == NULL)
        return false;
    if (root->val == n)
        return true;
    if (root->val < n)
        return search(root->right, n);
    else
        return search(root->left, n);
}

bool searchIt(Node *root, int n)
{
    if (root == NULL)
        return false;
    while (root)
    {
        if (root->val == key)
            return true;
        if (root->val < n)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->left->left = new Node(3);
    root->right->left->left = new Node(16);
    cout << search(root, 16) << endl
         << search(root, 19);
}