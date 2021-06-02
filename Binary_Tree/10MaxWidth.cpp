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
        left = NULL;
        right = NULL;
    }
};

int maxWidth(node *root)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int maxi = 1;
    while (!q.empty())
    {
        int n = q.size();
        maxi = max(n, maxi);
        for (int i = 0; i < n; i++)
        {
            node *t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return maxi;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->left = new node(9);
    root->right->right->right->left->right = new node(10);
    root->right->right->right->left->right->left = new node(11);
    cout << maxWidth(root);
}
