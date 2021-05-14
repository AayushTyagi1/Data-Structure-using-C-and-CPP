#include <iostream>
using namespace std;

long long catalan(int n)
{
    long long catalan[n + 1];
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += catalan(i) * catalan(n - i - 1);
        }
    }

    return catalan[n];
}

int main()
{
    int a;
    cin >> a;
    cout << catalan(a);
    return 0;
}