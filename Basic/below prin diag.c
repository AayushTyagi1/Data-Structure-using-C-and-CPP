#include<stdio.h>
void input( int[][10] , int);
void diag( int[][10] , int);
void main()
{
    int arr[10][10],a;
    printf("enter the a");
    scanf("%d%d",&a);
    input(arr,a);
}
void input(int arr[][10],int m)
{
    int i,j;
    printf("enter the matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    }
    diag(arr,m);
}
void diag(int arr[][10],int p)
{
    int i,j;
    for(i=1;i<p;i++)
    {
        for(j=0;j<p-1;j++)
        {
            if(i!=j)
                printf("%d\t",arr[i][j]);
        }
    }
}
