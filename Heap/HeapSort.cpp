#include <iostream>

using namespace std;
int size = 10;
int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
void maxHeapify(int i, int *arr)
{
    int small = i;
    if (left(i) < size && arr[left(i)] > arr[i])
        small = left(i);
    if (right(i) < size && arr[right(i)] > arr[i])
        small = right(i);
    if (i != small)
    {
        swap(arr[small], arr[i]);
        return maxHeapify(small, arr);
    }
}
void BuildHeap(int *arr)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        maxHeapify(i, arr);
    }
}
int main()
{
    int arr[10] = {10, 2, 4, 11, 8, 12, 15, 6, 3, 9};
    BuildHeap(arr);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    while (size != 0)
    {
        swap(arr[size - 1], arr[0]);
        size--;
        maxHeapify(0, arr);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}