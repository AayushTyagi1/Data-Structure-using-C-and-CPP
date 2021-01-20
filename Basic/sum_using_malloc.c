#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,sum=0;
    printf("Enter Limit:");
    scanf("%d",&n);
    int *p;
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
      scanf("%d",p+i);
      sum+=*(p+i);
    }
    printf("%d",sum);
}
