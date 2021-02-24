#include <stdio.h>
#define max 100 //Max size of an array

void swap(int *p, int *q)
{
    int temp = (*p);
    (*p) = (*q);
    *q = temp;
}
int main()
{
    int n, i, j, mini, pos, a[max], comparisons, swaps, T; // Variables definition
    scanf("%d", &T);
    while (T--)
    {
        comparisons = 0;
        swaps = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++) //Selection sort
        {
            mini = a[i];
            pos = i;
            for (j = i + 1; j < n; j++)
            {
                if (a[j] < mini)
                {
                    mini = a[j];
                    pos = j;
                }
                comparisons++;
            }
            if (pos != i)
            {
                swap(&a[i], &a[pos]);
                swaps++;
            }
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\ncomparisons %d\nswaps %d\n", comparisons, swaps);
    }
}
