#include <bits/stdc++.h>
using namespace std;
vector<int> findLPS(string str)
{
    int n = str.length();
    int len = 0;
    vector<int> lps(n);
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
            lps[i++] = ++len;
        else
        {
            if (len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }
    }
    return lps;
}
void KMP(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();
    vector<int> lps = findLPS(pat);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}
int main()
{
    string pat, txt;
    cin >> txt >> pat;
    KMP(pat, txt);
}