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

void DFS(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int v : adj[s])
    {
        if (!visited[v])
        {
            DFS(adj, v, visited);
        }
    }
}

void DFSDin(vector<int> a[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    DFS(a, s, visited);
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
    DFSDin(adj, V, 0);

    return 0;
}