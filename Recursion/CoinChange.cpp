#include <iostream>
using namespace std;
int getCount(int coins[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int res = getCount(coins, n - 1, sum);
    if (coins[n - 1] <= sum)
        res = res + getCount(coins, n, sum - coins[n - 1]);
    return res;
}
int main()
{
    int n = 3;
    int coins[] = {1, 2, 3};
    cout << getCount(coins, 3, 4);
}