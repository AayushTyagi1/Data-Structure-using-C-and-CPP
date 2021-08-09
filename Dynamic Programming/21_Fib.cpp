#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
//Top Down DP
int fib(int n, int dp[])
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != 0)
        return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}
//Bottom Up
int fibB(int n)
{
    int dp[n + 1] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//Bottom Up Optimizes
int fibBO(int n)
{
    if (n < 2)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
//LOGN
int fiblogBU(int n)
{
    unsigned long long fib[n + 1] = {0};
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i & 1)
        {
            unsigned long long a = fib[(i + 1) / 2];
            unsigned long long b = fib[(i + 1) / 2 - 1];
            fib[i] = a * a + b * b;
        }
        else
        {
            unsigned long long a = fib[i / 2];
            unsigned long long b = fib[i / 2 - 1];
            fib[i] = a * a + 2 * a * b;
        }
    }
    return fib[n];
}
unsigned long long fiblogNTD(unsigned long long n, int f[])
{
    if (n < 2)
        return n;
    if (f[n])
        return f[n];
    if (n & 1)
    {
        unsigned long long a = fiblogNTD((n + 1) / 2, f);
        unsigned long long b = fiblogNTD((n + 1) / 2 - 1, f);
        f[n] = a * a + b * b;
    }
    else
    {
        unsigned long long a = fiblogNTD(n / 2, f);
        unsigned long long b = fiblogNTD(n / 2 - 1, f);
        f[n] = a * a + 2 * a * b;
    }
    return f[n];
}
int main()
{
    int dp[100] = {0};
    cout << fib(19) << endl;
    cout << fib(19, dp) << endl
         << fibB(19) << " " << fibBO(19) << " " << fiblogBU(19) << " " << fiblogNTD(19, dp);
}