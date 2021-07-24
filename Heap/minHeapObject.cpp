#include <iostream>
using namespace std;
struct Person
{
    int age;
    float ht;
    Person(int a, float h)
    {
        age = a;
        ht = h;
    }
};
struct myCmp
{
    bool operator()(Person const &p1, Person const &p2)
    {
        p1.ht < p2.ht;
    }
};
int main()
{
    priority_queue<Person, vector<Person>, myCmp> pq;
    Person p(18, 12);
}