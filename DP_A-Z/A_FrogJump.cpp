#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int solve(vector<int> arr, int n)
{
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(abs(arr[i] - arr[i - 1]) + dp[i - 1], ((i == 1) ? INT_MAX : abs(arr[i] - arr[i - 2]) + dp[i - 2]));
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n);
}