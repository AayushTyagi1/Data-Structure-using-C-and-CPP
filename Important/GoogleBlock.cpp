#include <bits/stdc++.h>
using namespace std;

int dis(vector<map<int, bool>> block, vector<int> req)
{
    int n = block.size();
    int sol[n][req.size()];
    int mindis = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < req.size(); j++)
        {
            sol[i][j] = 99999999;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int currdis = -1;
        for (int j = 0; j < req.size(); j++)
        {
            if (block[i][req[j]])
                sol[i][j] = 0;
            else if (i != 0)
                sol[i][j] = min(sol[i][j], sol[i - 1][j] + 1);
            currdis = max(sol[i][j], currdis);
        }
        if (currdis < mindis)
            mindis = currdis;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int currdis = -1;
        for (int j = 0; j < req.size(); j++)
        {
            sol[i][j] = min(sol[i][j], sol[i + 1][j] + 1);
            currdis = max(sol[i][j], currdis);
        }
        if (currdis < mindis)
            mindis = currdis;
    }
    return mindis;
}
int main()
{
    vector<map<int, bool>> block(5);
    block[0][0] = 1;
    block[0][1] = 0;
    block[0][2] = 0;
    block[1][0] = 0;
    block[1][1] = 0;
    block[1][2] = 1;
    block[2][0] = 0;
    block[2][1] = 1;
    block[2][2] = 0;
    block[3][0] = 1;
    block[3][1] = 0;
    block[3][2] = 1;
    block[4][0] = 0;
    block[4][1] = 0;
    block[4][2] = 1;
    vector<int> req = {0, 2};
    cout << dis(block, req);
}