#include <iostream>
using namespace std;
void FirstRepeatedChar(string str)
{
    int i, len = str.size();
    int count[256];
    for (int i = 0; i < 256; i++)
        count[i] = 0;
    for (int i = 0; i < len; i++)
    {
        if (count[str[i]] == 1)
        {
            cout << str[i];
            break;
        }
        else
            count[str[i]]++;
    }
    if (i == len)
    {
        cout << "NO Repeated character";
    }
}
int main()
{
    string ch = "gasdhsahhrefd";
    FirstRepeatedChar(ch);
}