#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool DFS(vector<int> adj[], int i, vector<bool> &visited, vector<bool> &recst)
{
    visited[i] = true;
    recst[i] = true;
    for (auto u : adj[i])
    {
        if (!visited[u])
        {
            if (DFS(adj, u, visited, recst))
                return true;
        }
        else if (recst[u])
            return true;
    }
    recst[i] = false;
    return false;
}
bool DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false), recSt(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (DFS(adj, i, visited, recSt))
                return true;
    }
    return false;
}
int main()
{
    int V;
    V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if (DFS(adj, V))
        cout << "CYCLE DETECTED";
    else
        cout << "NO CYCLE DETECTED";
}