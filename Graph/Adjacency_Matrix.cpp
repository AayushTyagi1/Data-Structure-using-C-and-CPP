#include <iostream>
#include <stdlib.h>
using namespace std;

struct Graph
{
    int V;
    int E;
    int **Adj;
};

Graph *adjMatrixOfGraph()
{
    int u, v;
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (!G)
    {
        cout << "Memory Error" << endl;
        return NULL;
    }
    cout << "Number of V and E:";
    cin >> G->V >> G->E;
    G->Adj = (int **)malloc(sizeof(int *) * (G->V));
    for (int i = 0; i < G->V; i++)
        G->Adj[i] = (int *)malloc(sizeof(int) * G->V);
    for (int i = 0; i < (G->V); i++)
    {
        G->Adj[i][j] = 0;
    }

    for (int i = 0; i < G->E; i++)
    {
        cin >> u >> v;
        G->Adj[u][v] = 1;
        //Remove below line for Directed graph
        G->Adj[v][u] = 1;
    }
    for (int i = 0; i < (G->V); i++)
    {
        for (int j = 0; j < (G->V); j++)
            cout << G->Adj[i][j] << " ";
        cout << endl;
    }
    return G;
}

Graph *adjMatrixOfDirectedGraph()
{
    int u, v;
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (!G)
    {
        cout << "Memory Error" << endl;
        return NULL;
    }
    cout << "Number of V and E:";
    cin >> G->V >> G->E;
    G->Adj = (int **)malloc(sizeof(int *) * (G->V));
    for (int i = 0; i < G->V; i++)
        G->Adj[i] = (int *)malloc(sizeof(int) * G->V);
    for (int i = 0; i < (G->V); i++)
    {
        for (int j = 0; j < (G->V); j++)
            G->Adj[i][j] = 0;
    }

    for (int i = 0; i < G->E; i++)
    {
        cin >> u >> v;
        G->Adj[u][v] = 1;
    }
    for (int i = 0; i < (G->V); i++)
    {
        for (int j = 0; j < (G->V); j++)
            cout << G->Adj[i][j] << " ";
        cout << endl;
    }
    return G;
}

int main()
{
    Graph *G = adjMatrixOfGraph();
}
