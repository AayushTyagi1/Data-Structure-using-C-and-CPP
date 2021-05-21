#include <iostream>

using namespace std;

unsigned long int cat(int n)
{

    int a = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= i;
    }
    int b = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        b *= i;
    }
    int c = a * (n + 1);
    return b / (a * c);
}

int main()
{
    int n;
    n = 5;
    cout << cat(n);
}