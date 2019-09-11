#include<stdio.h>
void input( int[][10] , int , int);
void sum( int[][10] , int , int);
void main()
{
    int arr[10][10],a,b;
    printf("enter the a,b");
    scanf("%d%d",&a,&b);
    input(arr,a,b);
}
void input(int arr[][10],int m,int n )
{
    int i,j;
    printf("enter the matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    sum(arr,m,n);
}
void sum(int arr[][10],int p,int q)
{
    int i,j,s;
    for(i=0;i<p;i++)
    {
        s=0;
        printf("row %d\t",i+1);
        for(j=0;j<q;j++)
            s+=arr[i][j];
        printf("%d\n",s);
    }
    for(i=0;i<p;i++)
    {
        s=0;
        printf("column %d\t",i+1);
        for(j=0;j<q;j++)
            s+=arr[j][i];
        printf("%d\n",s);
    }

}
