#include<stdio.h>
int acr(int m ,int n)
{
    if(m==0)
    return(n+1);
    if(m>0&&n==0)
    return(acr(m-1,1));
    if(m>0&&n>0)
    return(acr(m-1,acr(m,n-1)));
}
int main()
{
    int a,b;
   printf("Enter the numbers:");
   scanf("%d%d",&a,&b);
   printf("%d",acr(a,b));

}