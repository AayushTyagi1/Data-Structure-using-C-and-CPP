#include <iostream>
using namespace std;

int mcuts(int n, int a, int b, int c)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    int res = max(mcuts(n - a, a, b, c), mcuts(n - b, a, b, c));
    res = max(res, mcuts(n - c, a, b, c));
    if (res == -1)
        return res;
    else
        return res + 1;
}

int main()
{
    cout << mcuts(23, 12, 11, 13);
    cout << endl
         << mcuts(5, 1, 2, 3);
}