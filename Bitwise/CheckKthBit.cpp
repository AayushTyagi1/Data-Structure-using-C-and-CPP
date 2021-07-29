#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    n >> (k - 1);
    cout << (n & 1);
}