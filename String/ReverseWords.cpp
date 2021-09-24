#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "Reverse this string word by word";
    string temp;
    stack<string> st;
    for (int i = 0; i < str.length(); i++)
    {
        temp = "";
        while (str[i] && str[i] != ' ')
        {
            temp += str[i];
            i++;
        }
        st.push(temp);
    }
    str = "";
    while (!st.empty())
    {
        str += st.top();
        str += " ";
        st.pop();
    }
    str.pop_back();
    cout << str;
}