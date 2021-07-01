#include <iostream>
using namespace std;

int sol(int arr[], int i, int j, int sum)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    else
        return max(sum - sol(arr, i + 1, j, sum - arr[i]), sum - sol(arr, i, j - 1, sum - arr[j]));
}

int mainsol(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sol(arr, 0, n - 1, sum);
}
int main()
{
    int arr[] = {20, 5, 4, 6};
    cout << mainsol(arr, 4);
}