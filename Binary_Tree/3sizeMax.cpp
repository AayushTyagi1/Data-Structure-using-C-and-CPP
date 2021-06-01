#include <iostream>
#include <climits>
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
int size(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
int getmax(node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        return max(root->key, max(getmax(root->left), getmax(root->right)));
    }
}
int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(70);
    cout << size(root) << endl;
    cout << getmax(root);
}