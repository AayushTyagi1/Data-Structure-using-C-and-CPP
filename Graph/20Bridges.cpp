#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void dfs(int s, int parent, vector<int> &visited, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    visited[s] = 1;
    tin[s] = low[s] = timer++;
    for (auto u : adj[s])
    {
        if (u == parent)
            continue;
        if (!visited[u])
        {
            dfs(u, s, visited, tin, low, timer, adj);
            low[s] = min(low[s], low[u]);
            if (low[u] > tin[s])
            {
                cout << s << " " << u << endl;
            }
        }
        else
        {
            low[s] = min(low[s], tin[u]);
        }
    }
}
void bridges(vector<int> adj[], int n)
{
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> visited(n, 0);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, -1, visited, disc, low, timer, adj);
    }
}
int main()
{
    int V = 5;
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    bridges(adj, V);
}