#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int *arr;
    int capacity;
    int size;

public:
    Heap(int c)
    {
        arr = new int[c];
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 15;
        arr[3] = 40;
        arr[4] = 50;
        arr[5] = 100;
        arr[6] = 25;
        arr[7] = 45;
        capacity = c;
        size = 8;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return ((i - 1) / 2); }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert(int n)
    {
        if (size == capacity)
            return;
        int pos = size;
        size++;
        arr[pos] = n;
        while (pos != 0 && arr[pos] < arr[parent(pos)])
        {
            swap(arr[parent(pos)], arr[pos]);
            pos = (pos - 1) / 2;
        }
    }
    void minHeapify(int i)
    {
        if (left(i) < size && arr[left(i)] < arr[i])
        {
            swap(arr[left(i)], arr[i]);
            return minHeapify(left(i));
        }
        if (right(i) < size && arr[right(i)] < arr[i])
        {
            swap(arr[right(i)], arr[i]);
            return minHeapify(right(i));
        }
        return;
    }
    void minExtract()
    {
        swap(arr[0], arr[size - 1]);
        size--;
        arr[size] = 0;
        minHeapify(0);
    }
};
int main()
{
    Heap obj(20);
    obj.display();
    obj.insert(12);
    obj.display();
    obj.minExtract();
    obj.display();
    obj.minExtract();
    obj.display();
}