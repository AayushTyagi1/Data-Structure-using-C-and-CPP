#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str, pat;
    cin >> str >> pat;
    vector<int> ind;
    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (pat[j] == str[i])
        {
            int temp = i;
            while (pat[j] && pat[j] == str[i])
            {
                i++;
                j++;
            }
            if (j == pat.length())
                ind.push_back(temp);
            j = 0;
            i = temp;
        }
    }
    for (int i = 0; i < ind.size(); i++)
    {
        cout << ind[i] << " ";
    }
}