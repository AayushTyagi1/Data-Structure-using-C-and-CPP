#include <iostream>
using namespace std;

void cum(int *arr, int i, int n)
{
    if (i == n)
        return;
    else
    {
        arr[i + 1] += arr[i];
        cum(arr, i + 1, n);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cum(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}