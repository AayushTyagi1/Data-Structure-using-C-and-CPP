#include<stdio.h>
int gcd(int,int);
void main()
{
    int n,a[20],hcf,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    hcf=gcd(a[0],a[1]);
    for(i=0;i<n-1;i++)
    {
        hcf=gcd(hcf,a[i+1]);
    }
    printf("gcd is %d",hcf);
}
int gcd(int a,int b)
{
    if(a==b)
        return a;
    else if (a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
