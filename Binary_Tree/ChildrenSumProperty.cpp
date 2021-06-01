#include <iostream>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int ChildrenSUm(node *root)
{

    if (root->left && root->right)
    {
        if (root->key != root->left->key + root->right->key)
            return 1;
        return 0 + ChildrenSUm(root->left) + ChildrenSUm(root->right);
    }
    else if (root->left)
    {
        if (root->key != root->left->key)
            return 1;
        return 0 + ChildrenSUm(root->left);
    }
    else if (root->right)
    {
        if (root->key != root->right->key)
            return 1;
        return 0 + ChildrenSUm(root->right);
    }
    else
    {
        return 0;
    }
}
int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(12);
    root->left->right = new node(8);
    root->right->left = new node(5);
    root->right->right = new node(7);
    root->right->left->left = new node(5);

    if (!ChildrenSUm(root))
        cout << "YES";
    else
        cout << "NO" << endl;
}
