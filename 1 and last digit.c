#include<stdio.h>
void main()
{
    int n,c;
    scanf("%d",&n);
    c=n%10;
    while(n/10>0)
    {
        n=n/10;
    }
    printf("%d\n",n);
    printf("%d",c);

}
