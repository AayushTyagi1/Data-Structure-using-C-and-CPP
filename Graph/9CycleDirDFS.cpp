#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
bool DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for (auto i : adj[s])
    {
        if (!visited[i] && DFSRec(adj, i, visited, recSt))
            return true;
        else if (recSt[i])
            return true;
    }
    recSt[s] = false;
    return false;
}
bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
    bool recSt[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (DFSRec(adj, i, visited, recSt))
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