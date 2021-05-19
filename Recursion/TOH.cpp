#include <iostream>

using namespace std;

TOH(int n, char i, char aux, char f)
{
    if (n > 0)
    {
        TOH(n - 1, i, f, aux);
        cout << "Move a disc from " << i << " to " << f << endl;
        TOH(n - 1, aux, i, f);
    }
}

int main()
{
    int n;
    printf("Enter n :");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
}
