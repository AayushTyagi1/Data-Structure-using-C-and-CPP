#include <iostream>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int k)
    {
        val = k;
        left = NULL;
        right = NULL;
    }
};
node *insert(node *root, int k)
{
    if (root == NULL)
    {
        return new node(k);
    }
    else if (root->val > k)
        root->left = insert(root->left, k);
    else if (root->val < k)
        root->right = insert(root->right, k);
    return root;
}
int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
}