#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int V;
    list<int> *G;

    graph(int n)
    {
        V = n;
        G = new list<int>[n];
    }

    void add_edge(int a, int b)
    {
        G[a].push_back(b);
    }

    bool has_edge(int a, int b)
    {
        if (a == b)
            return (true);

        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> q;
        visited[a] = true;
        q.push_back(a);
        list<int>::iterator i;
        while (!q.empty())
        {
            a = q.front();
            q.pop_front();

            for (i = G[a].begin(); i != G[a].end(); ++i)
            {
                if (*i == b)
                {
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
        return (false);
    }

    int count_nodes()
    {
        return (V);
    }

    int count_edges()
    {
        int count = 0;
        for (int i = 0; i < (*G).size(); i++)
        {
            count = count + G[i].size();
        }
        return (count);
    }

    int count_edges(int n)
    {
        int count;
        count = G[n].size();
        return (count);
    }

    vector<int> bfs(int n)
    {
        vector<int> v;
        bool visited[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;

        list<int> q;
        visited[n] = true;
        q.push_back(n);
        list<int>::iterator i;
        while (!q.empty())
        {
            n = q.front();
            v.push_back(n);
            q.pop_front();

            for (i = G[n].begin(); i != G[n].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
        return (v);
    }

    bool dfs(int n);

    bool is_connected(int a, int b)
    {
        if (a == b)
            return (true);

        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> q;
        visited[a] = true;
        q.push_back(a);
        list<int>::iterator i;
        while (!q.empty())
        {
            a = q.front();
            q.pop_front();

            for (i = G[a].begin(); i != G[a].end(); ++i)
            {
                if (*i == b)
                {
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
        return (false);
    }
};

int main()
{

    graph obj(4);
    obj.add_edge(0, 1);
    obj.add_edge(1, 2);
    obj.add_edge(2, 3);
    obj.add_edge(3, 0);

    if (obj.has_edge(1, 3))
        cout << "Yes edge is present\n";
    else
        cout << "No  edge is not present \n";

    int c = obj.count_nodes();
    cout << "No. of Nodes = " << c << "\n";
    int e = obj.count_edges();
    cout << "No. of Edges = " << e << "\n";
    if (obj.is_connected(3, 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}