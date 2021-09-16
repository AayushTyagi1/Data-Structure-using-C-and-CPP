#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void prism(vector<pair<int, int>> adj[], int V)
{
    vector<int> key(V, INT_MAX);
    vector<bool> MST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;
    for (int i = 0; i < V; i++)
    {
        int ind, mini = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if (MST[j] == false && key[j] < mini)
            {
                mini = key[j];
                ind = i;
            }
        }
        MST[ind] = true;
        for (auto i : adj[ind])
        {
            int v = i.first;
            int w = i.second;
            if (MST[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = ind;
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << parent[i] << "-" << i << " " << key[i] << endl;
}

int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    prism(adj, V);
}