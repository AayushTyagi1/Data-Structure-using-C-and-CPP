#include <iostream>
using namespace std;
void dectobin(int n)
{
    if (n == 0)
        return;
    dectobin(n / 2);
    cout << n % 2;
}
int main()
{
    dectobin(13);
}