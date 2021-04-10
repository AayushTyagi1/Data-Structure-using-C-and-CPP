#include <stdio.h>
#include <string.h>
#define RANGE 26

void countSort(char *arr)
{
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i)
        count[arr[i] - 'a']++;

    int max_ = 0, j;
    for (i = 0; i < RANGE; i++)
    {
        if (count[i] > max_)
        {
            max_ = count[i];
            j = i;
        }
    }
    if (max_ > 1)
        printf("%c - %d\n", 'a' + j, max_);
    else
        printf("No Duplicates Present");
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        char arr[n];
        scanf("%s", arr);
        countSort(arr);
    }

    return 0;
}
