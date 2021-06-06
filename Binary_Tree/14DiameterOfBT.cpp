#include <iostream>
#include <deque>
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

int diameter(node *root)
{
    if (root == NULL)
        return 0;
    static int res = 0;
    int lh, rh;

    lh = diameter(root->left);

    rh = diameter(root->right);
    res = max(res, lh + rh + 1);
    return 1 + max(lh, rh);
}
int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(70);
    cout << diameter(root);
}