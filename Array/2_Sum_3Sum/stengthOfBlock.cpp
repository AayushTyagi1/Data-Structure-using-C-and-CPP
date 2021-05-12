#include <bits/stdc++.h>
using namespace std;

int maxheight(vector<int> v)
{
    sort(v.begin(), v.end(), greater<int>());
    int N = v.size();
    if (N < 1)
    {
        return -1;
    }
    int count = 1;
    int i = 1;
    int l = v[0];
    while (l > 0 && i < N)
    {
        count++;
        l = min(l - 1, v[i]);
        i++;
    }
    return count;
}
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cout << maxheight(v);
}