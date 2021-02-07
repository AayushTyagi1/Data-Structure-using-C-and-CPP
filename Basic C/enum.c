#include<stdio.h>

enum days {sun,mon,tue,wed,thr,fri,sat};

enum bool {false, true};
typedef enum bool bool;

bool oddeven(int x)
{
    if(x%2==0)
        return true;
    else
        return false;
}


int main()
{

    enum days n;
    n=wed;

    bool a;
    a = oddeven(2);
    printf("%d",a);
}
