#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <= n; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
/***
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}
***/
int main ()
{
    int n = 5;

    cout << fib(n);
    return 0;
}
