#include <bits/stdc++.h>
using namespace std;

void printpath(int found)
{
    if (found == 1)
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Such Path Exists";
}

void DFS(vector<int> v[], bool vis[], int snode, int enode, vector<int> stak)
{
    int found = 0;
    stak.push_back(snode);
    if (snode == enode)
    {
        found = 1;
        printpath(found);
        return;
    }
    vis[snode] = true;
    if (!v[snode].empty())
    {
        for (int j = 0; j < v[snode].size(); j++)
        {
            if (vis[v[snode][j]] == false)
            {
                DFS(v, vis, v[snode][j], enode, stak);
            }
        }
    }
    stak.pop_back();
}

void DFSCall(int snode, int enode, vector<int> v[], int nodes, vector<int> stak)
{
    bool vis[nodes + 1];
    memset(vis, false, sizeof(vis));

    DFS(v, vis, snode, enode, stak);
}

int main()
{
    int nodes, n = 0, y = 0, z, snode, enode;
    cin >> nodes;
    vector<int> v[nodes], stak;
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
    cin >> snode;
    cin >> enode;
    snode--;
    enode--;
    DFSCall(snode, enode, v, nodes, stak);
    return 0;
}