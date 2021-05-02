#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, vector<int> v[], bool visited[])
{
    visited[u] = true;
    for (int i = 0; i < v[u].size(); i++)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(i, v, visited))
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> v[], int nodes)
{
    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
        visited[i] = false;
    for (int u = 0; u < nodes; u++)
    {
        if (!visited[u])
        {
            if (isCyclicUtil(u, v, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int nodes, n = 0, y = 0, z;
    cin >> nodes;
    vector<int> v[nodes];
    while (n < nodes)
    {
        if (y == nodes)
        {
            y = 0;
            n++;
        }
        if (n < nodes)
        {
            cin >> z;
            if (z == 1)
            {
                v[n].push_back(y);
            }
        }
        y++;
    }
    if (isCyclic(v, nodes))
        cout << "Yes Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";
    return 0;
}