#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Dijkastra(vector<pair<int, int>> adj[], int V, int s)
{
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    for (int i = 0; i < V; i++)
    {
        int ind = pq.top().second;
        pq.pop();
        for (auto i : adj[ind])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > w + dist[ind])
            {
                dist[v] = w + dist[ind];
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

int main()
{
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 7, 8, 7);
    addEdge(adj, 7, 6, 1);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 8, 6, 6);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 6, 5, 2);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 5, 4, 10);
    Dijkastra(adj, V, 0);
}