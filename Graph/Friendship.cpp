#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>> &arr, int v)
{

    if (arr[v][v] == 0)
        return 0;
    int area = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[v][i] == 1)
        {
            arr[v][i] = 0;
            area = 1 + dfs(arr, i);
        }
    }
    return area;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> a(V, vector<int>(V, 0));
    while (E--)
    {
        int i, j;
        cin >> i >> j;
        a[i - 1][j - 1] = 1;
        a[j - 1][i - 1] = 1;
    }
    for (int i = 0; i < V; i++)
    {
        a[i][i] = 1;
    }
    int noofgroups = 0;
    vector<int> area;
    for (int i = 0; i < V; i++)
    {
        if (a[i][i] == 1)
        {
            noofgroups++;
            int ar = dfs(a, i);
            area.push_back(ar);
        }
    }
    cout << noofgroups << endl;
    for (auto i : area)
    {
        cout << i << " ";
    }
}