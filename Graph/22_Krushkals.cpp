#include <iostream>
using namespace std;
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
bool myCmp(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}
int parent[V], rank[V];
int Kruskal(Edge arr[])
{
    sort(arr);
    for (int i = 0; i < V; i)
}
int main()
{
}