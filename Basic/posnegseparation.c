/*WAP a program to store n elements in an array & separate the positive and negative in same order*/
#include<stdio.h>
void main()
{
    int a[30],i,n,j,t;
    printf("enter limit:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
        for(j=i-1;j<n&&a[j]>0&&j>=0;j--)
        {
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
        }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

