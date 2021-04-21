#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int x = v[i].size();
            int y = v[i + 1].size();
            int minn = min(x, y);
            string a = v[i];
            string b = v[i + 1];
            for (int j = 0; j < minn; j++)
            {
                if (a[j] > b[j])
                {
                    v[i] = v[i + 1];
                    v[i + 1] = a;
                    i--;
                    break;
                }
                else if (a[j] < b[j])
                {

                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << endl;
        }
    }
}