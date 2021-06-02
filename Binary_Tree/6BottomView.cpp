#include <bits/stdc++.h>
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

void Botview(node *root)
{
    map<int, int> m;
    if (root == NULL)
        return;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        node *t = q.front().first;
        int h = q.front().second;
        m[h] = t->val;
        q.pop();
        if (t->left)
        {
            q.push({t->left, h - 1});
        }

        if (t->right)
            q.push({t->right, h + 1});
    }
    for (auto x : m)
        cout << x.second << " ";
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->left = new node(9);
    root->right->right->right->left->right = new node(10);
    root->right->right->right->left->right->left = new node(11);
    cout << endl
         << "Bottom VIEW: ";
    Botview(root);
}
