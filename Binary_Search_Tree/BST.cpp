#include <iostream>
using namespace std;

class BST
{
    int val;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST *insert(BST *, int);
    void inorder(BST *);
};
BST::BST()
{
    val = 0;
    left = NULL;
    right = NULL;
}
BST::BST(int val)
{
    this->val = val;
    left = right = NULL;
}
BST *BST::insert(BST *root, int k)
{
    if (root == NULL)
    {
        return new BST(k);
    }
    if (root->val > k)
        root->left = insert(root->left, k);
    else if (root->val < k)
        root->right = insert(root->right, k);
    return root;
}

void BST::inorder(BST *root)
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
    BST *root = NULL;
    BST b;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    b.inorder(root);
}