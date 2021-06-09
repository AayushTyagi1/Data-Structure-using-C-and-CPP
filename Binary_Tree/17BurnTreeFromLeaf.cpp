#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int timetaken(node *root, int n, int &dist)
{
    if (root == NULL)
        return 0;
    if (root->val == n)
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(70);
    root->left->left = new Node(30);
    root->left->left->right = new Node(50);
    cout << timetaken(root, 50)
}