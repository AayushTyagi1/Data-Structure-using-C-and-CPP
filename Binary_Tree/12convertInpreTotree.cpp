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

node *construct(vector<int> in, vector<int> pre, int s, int e)
{
    static int preI = 0;
    if (s > e)
        return NULL;
    node *root = new node(pre[preI++]);
    int inI;
    for (int i = s; i < e; i++)
    {
        if (root->val == in[i])
        {
            inI = i;
            break;
        }
    }
    root->left = construct(in, pre, s, inI - 1);
    root->right = construct(in, pre, inI + 1, e);
    return root;
}

int main()
{
    vector<int> in = {40, 20, 50, 10, 30, 80, 70, 90};
    vector<int> pre = {10, 20, 40, 50, 30, 0, 80, 90};
    node *root = construct(in, pre, 0, 8);
}