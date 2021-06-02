//Difference of Height of left and right subtree <=1

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int balance(node *root)
{
    if (root == NULL)
        return 0;
    int l = balance(root->left);
    int r = balance(root->right);
    if (l == -1)
        return -1;
    if (r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;
    else
        return max(l, r) + 1;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(70);
    cout << balance(root) << endl;
}