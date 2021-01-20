#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int n,i;
    printf("Enter size of the array:");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",p+i);
    i=0;
    int max=*p;
    int min=*p;
    while(i!=n)
    {
        if(*(p+i)>max)
            max=*(p+i);
        if(*(p+i)<min)
            min=*(p+i);
        i++;
    }
    printf("%d  %d",max,min);
}
