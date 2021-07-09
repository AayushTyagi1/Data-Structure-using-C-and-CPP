#include <iostream>
#include <vector>

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

bool findpath(node *root, vector<node *> &p, int n)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->key == n)
        return true;
    if (findpath(root->left, p, n) || findpath(root->right, p, n))
        return true;
    p.pop_back();
    return false;
}

node *lca(node *root, int a, int b)
{
    vector<node *> p1, p2;
    if (findpath(root, p1, a) && findpath(root, p2, b))
    {
        int i = 0;
        while (i < p1.size() - 1 && i < p2.size() - 1)
        {
            if (p1[i + 1] != p2[i + 1])
                return p1[i];
            i++;
        }
    }
    return NULL;
}

int finddepth(node *root, int n, int depth = 0)
{
    if (!root)
        return -1;
    if (root->key == n)
        return depth;
    int l = finddepth(root->left, n, depth + 1);
    if (l != -1)
        return l;
    int r = finddepth(root->right, n, depth + 1);
    if (r != -1)
        return r;
    return -1;
}
int findDis(node *root, int a, int b)
{
    if (!root)
        return -1;
    node *LCA = lca(root, a, b);
    if (LCA != NULL)
        return finddepth(root, a) + finddepth(root, b) - 2 * finddepth(root, LCA->key);
    return -1;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(70);
    cout << findDis(root, 50, 70) << endl;
    cout << findDis(root, 60, 30) << endl;
    cout << findDis(root, 40, 70) << endl;
}