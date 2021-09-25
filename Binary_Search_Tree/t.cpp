#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> &v, int i, int j, int n)
{
    if (i < 0 || j < 0 || i >= n || j >= n || v[i][j] == 0)
        return 0;
    int ans = 1;
    int t = j - 1 >= 0 ? check(v, i, j - 1, n) : 0;
    if (t == 0)
        return ans;
    t = j + 1 < n ? min(check(v, i, j + 1, n), t) : 0;
    if (t == 0)
        return ans;
    t = i + 1 < n ? min(check(v, i + 1, j, n), t) : 0;
    if (t == 0)
        return ans;
    t = i - 1 >= 0 ? min(check(v, i - 1, j, n), t) : 0;
    if (t == 0)
        return ans;
    ans += t;
    return ans;
}
int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
{
    vector<vector<int>> v(n, vector<int>(n, 1));
    for (int i = 0; i < mines.size(); i++)
    {
        v[mines[i][0]][mines[i][1]] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j])
            {
                if (i == 0 || i == n - 1 || j == 0, j == n - 1)
                    ans = max(ans, 1);
                ans = max(ans, check(v, i, j, n));
                if (ans == i + 1)
                    break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> m = {{4, 2}};
    cout << orderOfLargestPlusSign(5, m);
}