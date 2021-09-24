#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int arr[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            cout << char('a' + i) << " " << arr[i] << endl;
        }
    }
    return 0;
}