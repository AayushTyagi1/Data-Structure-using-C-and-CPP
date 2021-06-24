#include <iostream>
using namespace std;

int LCS(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
        return 1 + LCS(s1, s2, m - 1, n - 1);
    return max(LCS(s1, s2, m - 1, n), LCS(s1, s2, m, n - 1));
}
int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int m = s1.size();
    int n = s2.size();
    cout << LCS(s1, s2, m, n);
}