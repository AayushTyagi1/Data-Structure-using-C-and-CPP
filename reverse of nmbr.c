#include<stdio.h>
void main()
{
    int n,num=0;
    scanf("%d",&n);
    while(n>0)
    {
         num=num*10+n%10;
         n=n/10;
    }
    printf("%d",num);
}
