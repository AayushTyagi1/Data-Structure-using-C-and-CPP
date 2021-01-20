#include<stdio.h> #include<math.h>
void main()
{
    int n,i,a[30],d,b;
    printf("enter limit");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    d=a[1]-a[0];
    b=a[0];
    for(i=1;i<n;i++)
    {
        b=b+d;
        if(a[i]!=b)
            {printf("%d index %d",b,i);b+=d;}
    }
}
