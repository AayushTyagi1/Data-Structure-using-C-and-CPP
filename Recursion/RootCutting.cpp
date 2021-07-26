#include <iostream>
using namespace std;
int ropCutting(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(ropCutting(n - a, a, b, c), max(ropCutting(n - b, a, b, c), ropCutting(n - c, a, b, c)));
    if (res == -1)
        return res;
    return res + 1;
}
int main()
{
    int n = 23, a = 11, b = 9, c = 12;
    cout << ropCutting(n, a, b, c);
}