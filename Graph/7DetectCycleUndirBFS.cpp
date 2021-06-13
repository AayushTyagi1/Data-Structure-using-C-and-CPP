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

int BFS(vector<int> adj[], int v, int s)
{
    queue<int> q;
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        //cout << t << " ";
        for (int v : adj[t])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
            else if (v > t)
                return 1;
        }
    }
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
    if (BFS(adj, V, 0))
        cout << "CYCLE DETECTED";
    else
        cout << "No Cycle Detected";
}