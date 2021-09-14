#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
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

void DFS(vector<int> adj[], int s, vector<bool> &visited, stack<int> &st)
{
    visited[s] = true;
    for (int u : adj[s])
        if (!visited[u])
            DFS(adj, u, visited, st);
    st.push(s);
}

void DFS(vector<int> a[], int v)
{
    vector<bool> visited(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
        if (!visited[i])
            DFS(a, i, visited, st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);

    return 0;
}