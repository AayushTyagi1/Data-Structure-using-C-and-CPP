#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, wt;
    node(int _u, int _v, int _wt)
    {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<node> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;
    int inf = 10000000;
    vector<int> dist(V, inf);

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if (!fl)
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}