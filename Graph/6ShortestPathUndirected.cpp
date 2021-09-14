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
    vector<int> visited(V, false);
    vector<int> dest(V, INT_MAX);

    dest[0] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int u : adj[t])
        {
            if (!visited[u])
            {
                dest[u] = dest[t] + 1;
                visited[u] = true;
                q.push(u);
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << dest[i] << " ";
}

int main()
{
    int V = 6;
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 3, 5);
    ShortestPath(adj, 0, V);
}