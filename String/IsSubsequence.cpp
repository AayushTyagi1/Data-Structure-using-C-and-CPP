#include <iostream>
#include <cstring>
using namespace std;
bool isSub(string s1, string s2, int m, int n)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (s1[m - 1] == s2[n - 1])
        return isSub(s1, s2, m - 1, n - 1);
    return isSub(s1, s2, m, n - 1);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    while (j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            if (i == s1.length())
                break;
        }
        j++;
    }
    if (i == s1.length())
        cout << "YES";
    else
        cout << "NO";

    cout << endl
         << isSub(s1, s2, s1.length(), s2.length());
}