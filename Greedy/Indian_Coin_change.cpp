#include <iostream>
#include <algorithm>
using namespace std;

int make_change(int *arr, int n, int money)
{
    int ans = 0;
    while (money != 0)
    {
        if (arr[n] <= money)
        {
            cout << arr[n] << "+"
                 << " ";
            money -= arr[n];
            ans++;
        }
        else
            n--;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
    int n = 11;
    int amount = 5432;
    cout << make_change(arr, 10, amount);
}