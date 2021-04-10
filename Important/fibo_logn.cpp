#include <iostream>
using namespace std;

unsigned long long f[100];
unsigned long long fib(unsigned long long n)
{
    if (n < 2)
        return n;
    if (f[n])
        return f[n];
    if (n & 1)
    {
        unsigned long long a = fib((n + 1) / 2);
        unsigned long long b = fib((n + 1) / 2 - 1);
        f[n] = a * a + b * b;
    }
    else
    {
        unsigned long long a = fib(n / 2);
        unsigned long long b = fib(n / 2 - 1);
        f[n] = a * a + 2 * a * b;
    }
    return f[n];
}
int main()
{
    unsigned long long n;
    cin >> n;
    cout << fib(n);
}