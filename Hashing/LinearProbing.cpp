#include <bits/stdc++.h>

using namespace std;

class MyHash
{
    int *arr;
    int capacity, size;

public:
    MyHash(int c)
    {
        capacity = c;
        size = 0;
        arr = (int *)malloc(c * sizeof(int));
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % capacity;
    }
    bool insert(int key)
    {
        if (size == capacity)
            return false;
        int i = hash(key);
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
            i = (i + 1) % capacity;
        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }
    bool remove(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % capacity;
            if (i == h)
                return false;
        }
        return false;
    }
    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;
            i = (i + 1) % capacity;
            if (i == h)
                return false;
        }
        return false;
    }
};
int main()
{
    MyHash mh(7);
    cout << mh.insert(49);
    cout << mh.insert(56);
    cout << mh.insert(12);
    cout << mh.search(12);
    cout << mh.remove(12);
    cout << mh.search(12);
}