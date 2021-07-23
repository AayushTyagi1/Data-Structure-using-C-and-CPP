#include <bits/stdc++.h>
using namespace std;

int rate(long long c)
{
    if (c <= 10)
        return 10;
    if (c <= 239)
        return 5;
    if (c <= 559)
        return 8;
    if (c <= 1009)
        return 2;
    if (c <= 5000)
        return 7;
    if (c <= 10000)
        return 8;
    if (c <= 1000000000)
        return 3;
}
int charge(int ini, int fini)
{
    if (ini >= fini)
        return 0;
    int ans = 0;
    while (ini < fini)
    {
        ini += rate(ini);
        ans++;
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int ini, fin;
        cin >> ini >> fin;
        cout << charge(ini, fin);
    }
}