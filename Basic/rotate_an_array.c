#include<stdio.h>
#define max 30
int main()
{
    int a[max],k[max];
    int N,i,r,j=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    printf("Enter the rotating number:");
    scanf("%d",&r);
    for(i=0;i<N;i++)
    {
        if(i<r)
            k[i]=a[i];
        if(i+r<N)
        a[i]=a[i+r];
        else
            a[i]=k[j++];
    }
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
}
