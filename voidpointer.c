#include<stdio.h>
int main()
{
    int i;
    void *p;
    int a=20;
    p=&a;
    printf("%d\n",*(int*)p);
    float f=12.22;
    p=&f;
    printf("%f\n",*(float*)p);
    char c='A';
    p=&c;
    printf("%c\n",*(char *)p);
    int arr[]={1,2,3,4,5,6,7,8};
    p=arr;
    for(i=0;i<7;i++)
    {
        printf("%d\t",*(int*)p);
        p=(int *)p+1;
    }
}
