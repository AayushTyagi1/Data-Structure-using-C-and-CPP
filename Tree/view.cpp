#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void leftView(node *root)
{
    if (root == NULL)
        return;
    queue<pair<node *, int>> q;
    int l = 0;
    q.push({root, 1});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level > l)
        {
            l = level;
            cout << temp->data << " ";
        }
        if (temp->left)
        {
            q.push(make_pair(temp->left, level + 1));
        }
        if (temp->right)
        {
            q.push(make_pair(temp->right, level + 1));
        }
    }
}

void rightView(node *root)
{
    if (root == NULL)
        return;
    queue<pair<node *, int>> q;
    int l = 0;
    q.push({root, 1});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level > l)
        {
            l = level;
            cout << temp->data << " ";
        }
        if (temp->right)
        {
            q.push(make_pair(temp->right, level + 1));
        }
        if (temp->left)
        {
            q.push(make_pair(temp->left, level + 1));
        }
    }
}
void topView(node *root)
{
    if (root == NULL)
        return;
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (!m[hd])
        {
            m[hd] = temp->data;
        }
        if (temp->left)
        {
            q.push({temp->left, hd - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, hd + 1});
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->second << " ";
}
void bottomView(node *root)
{
    if (root == NULL)
        return;
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        m[hd] = temp->data;
        if (temp->left)
        {
            q.push({temp->left, hd - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, hd + 1});
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->second << " ";
}

node *insert(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main()
{
    node *root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->right = insert(4);
    root->right->left = insert(5);
    root->right->right = insert(6);
    root->right->left->left = insert(7);
    root->right->right->right = insert(8);
    root->right->right->right->left = insert(9);
    root->right->right->right->left->right = insert(10);
    root->right->right->right->left->right->left = insert(11);
    cout << endl
         << "LEFT VIEW: ";
    leftView(root);
    cout << endl
         << "RIGHT VIEW: ";
    rightView(root);
    cout << endl
         << "TOP VIEW: ";
    topView(root);
    cout << endl
         << "BOTTOM VIEW: ";
    bottomView(root);

    return 0;
}