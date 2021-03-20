#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int l, int r)
{
    int x = (rand() % (r - l + 1) + l);
    swap(&arr[x], &arr[r]);
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

int find(int *arr, int l, int r, int k)
{
    if (l <= r)
    {
        int pi = partition(arr, l, r);
        if (pi == k)
        {
            return arr[pi];
        }
        else if (pi < k)
        {
            return find(arr, pi + 1, r, k);
        }
        else
        {
            return find(arr, l, pi - 1, k);
        }
    }
    return -1;
}

double kthsmallest(int *arr, int n)
{
    int ans;
    return (find(arr, 0, n - 1, n / 2));
}

int main()
{
    srand(time(NULL));
    int arr[] = {12, 3, 5, 4, 4, 4, 4};
    int n = 7;
    cout << kthsmallest(arr, n);
    return 0;
}