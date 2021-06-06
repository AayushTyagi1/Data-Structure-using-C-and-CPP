#include <iostream>
#include <deque>
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

void spiral(node *root)
{
    deque<node *> q;
    q.push_back(root);
    int f = 0;
    while (!q.empty())
    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *t;
            if (f == 0)
            {
                t = q.front();
                q.pop_front();
            }

            else
            {
                t = q.back();
                q.pop_back();
            }
            cout << t->key << " ";
            if (t->left)
                q.push_back(t->left);
            if (t->right)
                q.push_back(t->right);
            (f == 0) ? (f = 1) : (f = 0);
        }
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
    spiral(root);
}