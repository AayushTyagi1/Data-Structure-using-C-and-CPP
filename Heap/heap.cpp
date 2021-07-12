#include <iostream>
using namespace std;
class Heap
{
    vector<int> arr;
    int capacity;
    int size;
    Heap(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
    }
    int left(int i) return 2 * i + 1;
    int right(int i) return 2 * i + 2;
    int parent(int i) return (i - 1) / 2;
};
int main()
{
}