#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}
void unionOp(int from, int to)
{
    from = find(from);
    to = find(to);
    parent[from] = to;
}
bool isCycle(vector<pair<int, int>> edges)
{
    for (auto p : edges)
    {
        int from = find(p.first);
        int to = find(p.second);
        if (from == to)
            return true;
        unionOp(from, to);
    }
    return false;
}
int main()
{
    int V, E;
    cin >> V >> E;
    parent.resize(V, -1);
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }
    if (isCycle(edgeList))
        cout << "CYCLE";
    else
        cout << "NO CYCLE";
}