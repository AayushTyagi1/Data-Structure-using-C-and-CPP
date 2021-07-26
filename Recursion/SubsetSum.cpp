#include <iostream>
using namespace std;

int subset(int arr[], int n, int sum)
{
    static int res;
    if (n == 0)
    {
        if (sum == 0)
            res++;
        return 0;
    }
    subset(arr, n - 1, sum);
    subset(arr, n - 1, sum - arr[n - 1]);
    return res;
}
int main()
{
    int n = 5, sum = 8;
    int arr[] = {10, 5, 2, 3, 6};
    cout << subset(arr, n, sum);
}