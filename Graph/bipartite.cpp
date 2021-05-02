#include <bits/stdc++.h>
using namespace std;
bool Bipartite(vector<int> vct[], int nodes, int s)
{
    int colorA[nodes];
    for (int i = 0; i < nodes; ++i)
        colorA[i] = -1;
    colorA[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int w = q.front();
        q.pop();
        for (int v = 0; v < nodes; ++v)
        {
            if (vct[w][v] && colorA[v] == -1)
            {
                colorA[v] = 1 - colorA[w];
                q.push(v);
            }
            else if (vct[w][v] && colorA[v] == colorA[w])
                return false;
        }
    }
    return true;
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
    if (Bipartite(v, nodes, 0))
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
    return 0;
}