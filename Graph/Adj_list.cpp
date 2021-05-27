#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node **adjList()
{
    int i, u, v;
    Node *temp;
    int V, E;
    cin >> V >> E;
    Node **arr;
    for (int i = 0; i < V; i++)
    {
        arr[i] = (Node *)malloc(sizeof(Node));
        arr[i]->val = i;
        arr[i]->next = arr[i];
    }

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        int j = u;
        while (arr[j]->next != arr[u])
        {
            arr[j] = arr[j]->next;
        }
        arr[j]->next = (Node *)malloc(sizeof(Node));
        arr[j] = arr[j]->next;
        arr[j]->val = v;
        arr[j]->next = arr[u];
    }

    return arr;
}
int main()
{
    Node **G = adjList();
}
