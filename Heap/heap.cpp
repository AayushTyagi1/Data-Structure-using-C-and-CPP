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
    int minExtract()
    {
        if (size == 0)
            return INT_MAX;
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    void deleteKey(int k)
    {
        decreaseKey(k, INT_MIN);
        minExtract();
    }
    void BuildHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--) //Bottom most right most noed
        {
            minHeapify(i);
        }
    }
};
int main()
{
    Heap obj(20);
    obj.display();
    obj.insert(12);
    obj.display();
    cout << obj.minExtract() << endl;
    obj.display();
    cout << obj.minExtract() << endl;
    obj.display();
    obj.decreaseKey(5, 5);
    obj.display();
    obj.deleteKey(5);
    obj.display();
    Heap obj2(20);
    obj2.display();
    obj2.BuildHeap();
    obj2.display();
}