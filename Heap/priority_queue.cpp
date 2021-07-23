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
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(10);
    q.push(5);
    q.push(20);
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    vector<int> v = {10, 5, 7, 30, 4};
    int arr[] = {9, 5, 2, 1, 6};
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + 5);
    priority_queue<int> newp(v.begin(), v.end());
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}