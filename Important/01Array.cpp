#include <iostream>
using namespace std;

int modify(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 1)
        {
            swap(arr[i], arr[j]);
            j--;
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
    modify(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}