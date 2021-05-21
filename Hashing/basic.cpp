#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class MyHash
{
    int bucket;
    list<int> *table;

public:
    MyHash(int bucket)
    {
        this->bucket = bucket;
        table = new list<int>[bucket];
    }

    void insert(int key)
    {
        int i = key % bucket;
        table[i].push_back(key);
    }
    bool search(int key)
    {
        int i = key % bucket;
        for (auto x : table[i])
        {
            if (x == key)
                return true;
        }
        return false;
    }
    void remove(int key)
    {
        int i = key % bucket;
        table[i].remove(key);
    }
};
int main()
{
    MyHash h(7);
    h.insert(56);
    h.insert(21);
    h.insert(42);
    cout << h.search(21);
    h.remove(22);
    cout << h.search(21);
}