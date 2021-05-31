
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

int height(node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
void kdistance(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    kdistance(root->left, k - 1);
    kdistance(root->right, k - 1);
}
void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        cout << t->key << " ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
}
void levelOrderLine(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        node *t = q.front();
        q.pop();
        if (t == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << t->key << " ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
}
void levelOrderLine2(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << t->key << " ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
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
    cout << height(root) << endl;
    kdistance(root, 2);
    cout << endl;
    levelOrder(root);
    cout << endl;
    levelOrderLine(root);
    cout << endl;
    levelOrderLine2(root);
}