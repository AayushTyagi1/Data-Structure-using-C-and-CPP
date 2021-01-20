#include<stdio.h>
void main()
{
    int n,i,a[30],d,f=0;
    printf("enter limit");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    d=a[1]-a[0];
    for(i=1;i<n-1;i++)
    {
        if((a[i+1]-a[i])!=d)
            f=1;
    }
    f==0?printf("IN AP"):printf("Not in AP");
}
