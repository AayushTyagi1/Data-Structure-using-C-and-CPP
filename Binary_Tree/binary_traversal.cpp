#include <iostream>
#include <stack>
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

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void preorderIt(node *root)
{
    stack<node *> s;
    while (1)
    {
        if (root)
        {
            cout << root->key << " ";
            s.push(root);
            root = root->left;
        }
        else if (s.empty())
            break;
        else
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

void inorderIt(node *root)
{
    stack<node *> s;
    while (1)
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else if (s.empty())
            break;
        else
        {
            root = s.top();
            cout << root->key << " ";
            s.pop();
            root = root->right;
        }
    }
}
void postorderIt(node *root)
{
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *t = s1.top();
        s1.pop();
        s2.push(t);
        if (t->left)
            s1.push(t->left);
        if (t->right)
            s1.push(t->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->key << " ";
        s2.pop();
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    cout << "Preorder Recursive" << endl;
    preorder(root);
    cout << "\nPreorder Iterative" << endl;
    preorderIt(root);
    cout << "Inorder Recursive" << endl;
    inorder(root);
    cout << "\nInorder Iterative" << endl;
    inorderIt(root);
    cout << "\nPostorder Recursive" << endl;
    postorder(root);
    cout << "\nPostorder Iterative" << endl;
    postorderIt(root);
}