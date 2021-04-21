#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i)
{
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int maximum = i;
    if (c1 < n && arr[c1] > arr[maximum])
    {
        maximum = c1;
    }
    if (c2 < n && arr[c2] > arr[maximum])
    {
        maximum = c2;
    }
    if (maximum != i)
    {
        swap(&arr[i], &arr[maximum]);
        heapify(arr, n, maximum);
    }
}

void build(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Before Sorintg\n";
    print(arr, n);
    build(arr, n);
    cout << "After Sorintg\n";
    print(arr, n);
    return 0;
}