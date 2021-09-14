#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v, int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;
}

int BFS(vector<int> adj[], int V, int indegree[])
{
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i : adj[u])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    int V;
    V = 6;
    vector<int> adj[V];
    int indegree[V];
    for (int i = 0; i < V; i++)
        indegree[i] = 0;
    addEdge(adj, 0, 2, indegree);
    addEdge(adj, 0, 3, indegree);
    addEdge(adj, 1, 3, indegree);
    addEdge(adj, 1, 4, indegree);
    addEdge(adj, 4, 5, indegree);
    BFS(adj, V, indegree);
}