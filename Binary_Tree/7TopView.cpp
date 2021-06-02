#include <bits/stdc++.h>
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
void createview(node *root, map<int, int> &h, int level = 0)
{
    if (h.find(level) == h.end())
    {
        h.insert({level, root->key});
    }
    if (root->left)
        createview(root->left, h, level - 1);
    if (root->right)
        createview(root->right, h, level + 1);
}
void topview(node *root)
{
    map<int, int> h;
    createview(root, h);
    for (auto i : h)
    {
        cout << i.second << " ";
    }
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
         << "Top VIEW: ";
    topview(root);
}
