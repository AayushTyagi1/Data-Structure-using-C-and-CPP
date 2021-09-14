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

void BFS(vector<int> adj[], int v, int s)
{
    queue<int> q;
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    int v;
    v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    print(adj, v);
    BFS(adj, 4, 0);
}