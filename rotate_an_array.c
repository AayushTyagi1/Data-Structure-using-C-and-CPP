#include<stdio.h>
int main()
{
    int a[7]={3,4,5,2,1,8,9};
    int i;int k=3;
    int b[k];
    for(i=0;i<7;i++)
    {
        if(i<k)
            b[i]=a[i];
        if((i+k)<7) a[i]=a[(i+k)];
        else a[i]=b[i-(7-k)];
    }
    for(i=0;i<7;i++)
        printf("%d ",a[i]);
}
