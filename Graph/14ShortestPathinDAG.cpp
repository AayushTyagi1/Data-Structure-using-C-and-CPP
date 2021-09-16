#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
}

void DFS(vector<pair<int, int>> adj[], int i, vector<bool> &visited, stack<int> &st)
{
    visited[i] = true;
    for (auto u : adj[i])
    {
        if (!visited[u.first])
        {
            DFS(adj, u.first, visited, st);
        }
    }
    st.push(i);
}
void DFS(vector<pair<int, int>> adj[], int V, int s)
{
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(adj, i, visited, st);
    }
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    while (!st.empty())
    {
        for (auto i : adj[st.top()])
        {
            if (dist[i.first] > dist[st.top()] + i.second)
            {
                dist[i.first] = dist[st.top()] + i.second;
            }
        }
        st.pop();
    }
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
}
int main()
{
    int V;
    V = 6;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 5, 3, 1);
    DFS(adj, 6, 0);
}