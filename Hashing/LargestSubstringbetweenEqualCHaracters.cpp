#include <bits/stdc++.h>
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(n - r));
}

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            zero++;
    }
    long long sum = 0;
    for (int i = ; i <= n; i++)
    {
        sum += nCr(n, i);
    }
    cout << sum;
}
