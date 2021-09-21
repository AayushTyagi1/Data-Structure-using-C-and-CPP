#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
}
void DFS(vector<int> adj[], stack<int> &st, vector<bool> &visited, int s)
{
    visited[s] = true;
    for (int i : adj[s])
    {
        if (!visited[i])
            DFS(adj, st, visited, i);
    }
    st.push(s);
}
void revDFS(vector<int> adj[], vector<bool> &visited, int s)
{
    visited[s] = true;
    cout << s + 1 << " ";
    for (int i : adj[s])
    {
        if (!visited[i])
            revDFS(adj, visited, i);
    }
}
void Kosaraju(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(adj, st, visited, i);
    }

    vector<int> transpose[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        for (auto u : adj[i])
            transpose[u].push_back(i);
    }

    while (!st.empty())
    {
        if (!visited[st.top()])
        {
            revDFS(transpose, visited, st.top());
            cout << endl;
        }

        st.pop();
    }
}
int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    Kosaraju(adj, 5);
}