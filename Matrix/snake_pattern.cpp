#include <iostream>
using namespace std;

void print(int mat[3][4], int m, int n)
{
    int i = 0, j = 0;
    while (i < m)
    {
        while (j < n)
        {
            cout << mat[i][j] << " ";
            j++;
        }
        j--;
        i++;
        if (i >= m)
            break;
        while (j >= 0)
        {
            cout << mat[i][j] << " ";
            j--;
        }
        i++;
        j++;
    }
}
int main()
{
    int mat[3][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
    };
    print(mat, 3, 4);
}