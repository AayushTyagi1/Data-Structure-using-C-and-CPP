#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> p;
    p.push(10);
    p.push(15);
    p.push(5);
    while (!p.empty())
    {
        cout << p.top() << endl;
        p.pop();
    }
}