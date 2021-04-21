#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *children[26];
    bool isEndOfWord;
};

Node *getNode()
{
    Node *p = new Node();

    p->isEndOfWord = false;

    for (int i = 0; i < 26; i++)
        p->children[i] = NULL;

    return p;
}

void insert(Node *root, string key)
{
    Node *p = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!p->children[index])
            p->children[index] = getNode();

        p = p->children[index];
    }
    p->isEndOfWord = true;
}

bool search(struct Node *root, string key)
{
    struct Node *p = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!p->children[index])
            return false;

        p = p->children[index];
    }

    return (p != NULL && p->isEndOfWord);
}

bool hasChild(Node *root)
{
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
}

Node *remove(Node *root, string word, int i = 0)
{
    if (!root)
        return NULL;

    if (i == word.length())
    {
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (hasChild(root))
        {
            delete (root);
            root = NULL;
        }

        return root;
    }

    root->children[word[i] - 'a'] =
        remove(root->children[word[i] - 'a'], word, i + 1);

    if (hasChild(root) && root->isEndOfWord == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

int main()
{
    Node *root = getNode();
    insert(root, "max");
    insert(root, "manner");
    insert(root, "cow");
    insert(root, "matter");
    insert(root, "dog");
    return 0;
}