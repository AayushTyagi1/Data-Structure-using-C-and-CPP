#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int l, int r, int &comp, int &swp)
{
    int pivot = arr[r];
    static int re[3];

    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        comp++; //comparisons
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swp++; //swaps
        }
    }
    swp++; //swap
    swap(&arr[i + 1], &arr[r]);

    return i + 1;
}
void quickSort(int *arr, int l, int r, int *res)
{
    int comp = 0, swap = 0;

    if (l < r)
    {

        int p = partition(arr, l, r, comp, swap);
        quickSort(arr, l, p - 1, res);
        quickSort(arr, p + 1, r, res);
    }
    res[0] = res[0] + comp;
    res[1] = res[1] + swap;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d   ", arr[i]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int res[2] = {0};
        quickSort(arr, 0, n - 1, res);
        print(arr, n);
        printf("\nno. of comparisions are: %d \nno. of  swaps = %d\n", res[0], res[1]);
    }
}
