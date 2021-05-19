#include <iostream>
using namespace std;

int check(int *arr, int n)
{
    if (n == 1)
        return 1;
    if (arr[n - 1] > arr[n - 2])
    {
        check(arr, n - 1);
    }
    else
        return 0;
}

int main()
{
    int arr[] = {4, 5, 6, 8, 9};
    cout << check(arr, 5);
    int b[] = {1, 6, 3, 2, 4};
    cout << check(b, 5);
}