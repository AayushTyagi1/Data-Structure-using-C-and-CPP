//Detect Cycle in Undirected Graph BFS
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

int DFS(vector<int> adj[], int s, vector<bool> &visited, int parent)
{
    visited[s] = true;
    for (int i : adj[s])
    {
        if (!visited[i])
        {
            if (DFS(adj, i, visited, i))
                return 1;
        }
        else if (i != parent)
        {

            return 1;
        }
    }
    return 0;
}
int DFScall(vector<int> adj[], int V, int s)
{
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
        visited[i] = false;
    if (DFS(adj, s, visited, -1))
        return 1;
    return 0;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    //print(adj, v);
    if (DFScall(adj, V, 0))
        cout << "CYCLE DETECTED";
    else
        cout << "No Cycle Detected";
}