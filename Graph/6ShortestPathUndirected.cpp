#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void ShortestPath(vector<int> adj[], int s, int V)
{
    vector<int> visited(V);
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<int> dist(V);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        //cout << t << " ";

        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
}

int main()
{
    int V = 4;
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    ShortestPath(adj, 0, V);
}