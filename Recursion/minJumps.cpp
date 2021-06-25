#include <iostream>
#include <climits>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (i + arr[i] >= n - 1)
        {
            int subres = minJumps(arr, i + 1);
            if (subres != INT_MAX)
            {
                res = min(res, subres + 1);
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {3, 4, 3, 1, 2, 1};
    cout << minJumps(arr, 6);
}