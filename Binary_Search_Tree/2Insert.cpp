#include <iostream>

using namespace std;

struct node
{
    int val;
    node *left, *right;
    node(int k)
    {
        val = k;
        left = NULL;
        right = NULL;
    }
};

void insert(node **root, int k)
{
    if (*root == NULL)
    {
        *root = new node(k);
    }
    else if ((*root)->val > k)
        insert(&(*root)->left, k);
    else
        insert(&(*root)->right, k);
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
int main()
{
    node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    inorder(root);
}