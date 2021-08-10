/*
1 <= N,M <= 100000
Problem Description:
Given a floor of size <b>n x m</b>. Find the number of ways to tile the floor with tiles of size <b> 1 x m </b>. A tile can either be placed horizontally or vertically.

Input Format: First line of input contains an integer <b>T</b> denoting the number of test cases. Then T test cases follow. <br />The first line of each test case contains two integers <b>N</b> and <b>M</b>.
Sample Input: 2
2 3
4 4
Output Format: Print answer for every test case in a new line modulo <b>10^9+7</b>.
Sample Output: 1
2
*/
#include <iostream>
#include <vector>
long long mod = 1e9 + 7;
using namespace std;
int countWays(int n, int m)
{
    if (n < 1)
        return 0;
    if (n < m)
        return 1;
    if (n == m)
        return 2;
    return countWays(n - 1, m) + countWays(n - m, m);
}
int count(int n, int m)
{
    if (n < 1)
        return 0;
    if (n < m)
        return 1;
    if (n == m)
        return 2;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        dp[i] += (i - m >= 0) ? dp[i - m] : 0;
        dp[i] %= mod;
    }
    return dp[n];
}
int main()
{
    int N, M;
    cin >> N >> M;
    cout << count(N, M);
}