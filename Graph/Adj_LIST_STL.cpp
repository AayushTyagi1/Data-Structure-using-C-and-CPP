#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e, src, des;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < v; i++)
    {
        g[i].push_back(i);
    }
    for (int i = 0; i < e; i++)
    {
        cin >> src >> des;
        g[src].push_back(des);
        g[des].push_back(src);
    }
    cout << "List: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << g[i][0] << "    ";
        for (int j = 1; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}
