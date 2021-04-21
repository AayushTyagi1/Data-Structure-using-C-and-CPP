#include <iostream>
#include <queue>
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
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void rightView(node *root)
{
    if (root == NULL)
        return;
    // queue<pair<node *, int>> q;
    int l = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == n)
                cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
void bfs(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
// void insert(node **root, int key)
// {
//     node *crr, *prev;
//     node *ptr = new node();
//     if (ptr == NULL)
//     {
//         cout << "en" << endl;
//         return;
//     }
//     ptr->data = key;
//     ptr->left = NULL;
//     ptr->right = NULL;
//     if (ptr == *root)
//     {
//         cout << "root" << endl;
//         *root = ptr;
//         (*root)->left = (*root)->right = NULL;
//         return;
//     }
//     else
//     {
//         crr = *root;
//         while (crr)
//         {
//             prev = crr;
//             if (crr->data > key)
//                 crr = crr->left;
//             else
//                 crr = crr->right;
//         }
//         if (prev->data > key)
//             prev->left = ptr;
//         else
//             prev->right = ptr;
//     }
// }
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
    root->left->left = insert(4);
    root->left->right = insert(5);
    bfs(root);
    cout << endl;
    leftView(root);
    cout << endl;
    rightView(root);
    return 0;
}