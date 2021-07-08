#include <iostream>
using namespace std;

struct trieNode
{
    bool isWord;
    trieNode *next[26];
    trieNode()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

void insert(string str, trieNode *root)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (root->next[str[i] - 'a'] == NULL)
            root->next[str[i] - 'a'] = new trieNode();
        root = root->next[str[i] - 'a'];
    }
    root->isWord = true;
}

bool search(string str, trieNode *root)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (root->next[str[i] - 'a'] == NULL)
            return false;
        root = root->next[str[i] - 'a'];
    }
    return (root != NULL && root->isWord);
}

bool isChildren(trieNode *root)
{
    for (int i = 0; i < 26; i++)
        if (root->next[i])
            return true;
    return false;
}

trieNode *deleteStr(string str, trieNode *root, int i)
{
    if (root == NULL)
        return root;
    if (i == str.length())
    {
        root->isWord = false;
        if (!isChildren(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    int ind = str[i] - 'a';
    root->next[ind] = deleteStr(str, root->next[ind], i + 1);
    if (!isChildren(root) && !root->isWord)
    {
        delete root;
        root = NULL;
    }
    return root;
}

int main()
{
    trieNode *root = new trieNode();
    string str;
    int ch;
    do
    {
        cout << "\n PRESS 1 to insert\n2 to search\n3 to delete" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> str;
            insert(str, root);
            break;
        case 2:
            cin >> str;
            if (search(str, root))
                cout << str << " is present" << endl;
            else
                cout << str << " is not present" << endl;
            break;
        case 3:
            cin >> str;
            deleteStr(str, root, 0);
            break;
        default:
            cout << "Please choose correct option";
        }
    } while (1);
}