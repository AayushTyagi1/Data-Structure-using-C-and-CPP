#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left, *right;
    node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
node *insert(node *root, int k)
{
    if (root == NULL)
    {
        root = new node(k);
        return root;
    }
    else if (k < root->val)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
node *inorderSuc(node *root)
{
    inorderSuc(root->left);
    if (!root->left && !root->right)
        return root;
    inorderSuc(root->right);
}
node *getsuccesor(node *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
node *deleteNode(node *root, int k)
{
    if (!root)
        return root;
    if (k < root->val)
        root->left = deleteNode(root->left, k);
    else if (k > root->val)
        root->right = deleteNode(root->right, k);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right = NULL)
        {
            node *temp = root->left;
            delete (root);
            return root->left;
        }
        else
        {
            node *succ = inorderSuc(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, k);
        }
    }
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
    deleteNode(root, 20);
    inorder(root);
}