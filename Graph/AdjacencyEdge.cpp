#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, src, des, weight;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> g;            //weight source destination
    vector<pair<int, pair<int, int>>>::iterator it; //weight source destination

    for (int i = 0; i < e; i++)
    {
        cin >> weight >> src >> des;
        g.push_back(make_pair(weight, make_pair(src, des)));
    }
    cout << "List: " << endl;
    for (it = g.begin(); it != g.end(); it++)
    {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    }
}
