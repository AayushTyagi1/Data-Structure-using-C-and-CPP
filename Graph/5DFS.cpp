#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j : adj[i])
            cout << j << " ";
        cout << endl;
    }
}

void DFS(vector<int> adj[], int s, vector<bool> &visited)
{
    cout << s << " ";
    visited[s] = true;
    for (int u : adj[s])
        if (!visited[u])
            DFS(adj, u, visited);
}

void DFS(vector<int> a[], int v)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
        if (!visited[i])
            DFS(a, i, visited);
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    cout << "Following is DEPTH First Traversal: " << endl;
    DFS(adj, V);

    return 0;
}