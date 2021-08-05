#include <iostream>
#include <algorithm>
using namespace std;

int make_change(int *arr, int n, int money)
{
    int ans = 0;
    while (money != 0)
    {
        int ind = upper_bound(arr, arr + n, money) - 1 - arr;
        cout << arr[ind] << "+"
             << " ";
        money -= arr[ind];
        ans++;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
    int n = 11;
    int amount = 5432;
    cout << make_change(arr, n, amount);
}