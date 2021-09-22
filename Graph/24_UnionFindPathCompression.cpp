#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rank_;
int find(int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i]);
}
void unionOp(int from, int to)
{
    if (rank_[from] > rank_[to])
        parent[to] = from;
    else if (rank_[from] < rank_[to])
        parent[from] = to;
    else
    {
        parent[from] = to;
        rank_[to]++;
    }
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
    rank_.resize(V, 0);
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