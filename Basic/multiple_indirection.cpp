#include<iostream>
using namespace std;
#define length 5
int data[length];
int main()
{
    int *p;int i;
    int **pp;
    for(i=0;i<length;i++)
        data[i]=i;
    for(i=0;i<length;i++)
        cout<<data[i];
    p=data;
    pp=&p;
    for(i=0;i<length;i++)
    {
        cout<<"\nloop &  array address "<<i<<data;
        cout<<"\npointed by p "<<*p;
        cout<<"\npointed by pp "<<*pp;
        cout<<"\npointed by double indirection "<<**pp;
        cout<<"\nValue of pp and address of p "<<&p<<'\t'<<pp;
        p+=1;
    }
}
