#include <bits/stdc++.h>
using namespace std;
int sol(int start, int end, int y)
{
    int count = 0;
    int digsum = 0;
    for (int i = start; i <= end; i++)
    {
        int num = i;
        digsum = 0;
        while (num > 0)
        {
            digsum += num % 10; //sum of digits
            num = num / 10;
        }
        if (digsum == y) //original number is i{
            count++;
        //cout<<i<<" ";
    }
}
return count;
}
int main()
{
    int START = 1;
    int END;
    cin >> END;
    sol(START, END);
    return 0;
}