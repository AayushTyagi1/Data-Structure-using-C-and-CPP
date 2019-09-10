#include<stdio.h>
void main()
{
    int n,f,c,k;
    scanf("%d",&n);
    for(;n>0;n=n/10)
    {
        f=0;
        c=n;
        for(k=c%10;c>0;c=c/10)
        {
             if(k==c%10)
             f++;
        }
        if()
        printf("%d and frequency %d\n",k,f);
    }
}
