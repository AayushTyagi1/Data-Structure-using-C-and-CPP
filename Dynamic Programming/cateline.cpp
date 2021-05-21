#include <iostream>
using namespace std;

long long cat(int n)
{
    long long catalan[n + 1];
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main()
{
    int a;
    cin >> a;
    cout << cat(a);
    return 0;
}