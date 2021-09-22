#include <bits/stdc++.h>
using namespace std;
vector<int> parent, rankP;

struct Edge
{
    int src, dest, wt;
    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};
vector<Edge> mst;
int find(int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i]);
}
void unionop(int fromP, int toP)
{
    if (rankP[fromP] > rankP[toP])
    {
        parent[toP] = fromP;
    }
    else if (rankP[fromP] < rankP[toP])
    {
        parent[fromP] = toP;
    }
    else
    {
        parent[fromP] = toP;
        rankP[toP]++;
    }
}
bool myCmp(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}

int Kruskal(vector<Edge> &arr, int V, int E)
{
    sort(arr.begin(), arr.end(), myCmp);
    int i = 0, j = 0;
    while (i < V && j < E)
    {
        int fromP = find(arr[j].src);
        int toP = find(arr[j].dest);
        if (fromP == toP)
            j++;
        else
        {
            unionop(fromP, toP);
            mst.push_back(arr[j]);
            i++;
        }
    }
}
void printMST(vector<Edge> &mst)
{
    for (auto p : mst)
    {
        cout << p.src << " " << p.dest << endl;
    }
}
int main()
{
    int E, V;
    cin >> E >> V;
    parent.resize(V, -1);
    rankP.resize(V, 0);
    vector<Edge> edgelist;
    for (int i = 0; i < E; i++)
    {

        int from, to, wt;
        cin >> from >> to >> wt;
        Edge temp(from, to, wt);
        edgelist.push_back(temp);
    }
    Kruskal(edgelist, V, E);
    printMST(mst);
}