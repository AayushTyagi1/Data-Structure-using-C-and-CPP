#include<stdio.h>
#include<math.h>
#define max 100

int jump_Search(int a[], int n, int key)
{
    int start = 0;
    int end = sqrt(n);
    int count=0;

    while(a[end] <= key && end < n)
    {
        count++;
        start = end;
        end += sqrt(n);
        if(end > n - 1)
            end = n;
    }

    for(int i = start; i<end; i++)
    {
        count++;
        if(a[i] == key)
            return count;
    }
    return -(count-1);
}

int main()
{
    int n, T, a[max],key,count;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i< n; i++)
        {
            scanf("%d",&a[i]);;
        }
        scanf("%d",&key);

        count = jump_Search(a, n, key);
        if(count>=0)
        {
            printf("PRESENT\n");
            printf("Number of comparisons: %d",count);
        }
        else
        {
            printf("NOT PRESENT\n");
            printf("Number of comparisons: %d",-count);
        }

    }
}
