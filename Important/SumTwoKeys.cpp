
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{
    int n, pos, mpos;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        pos = i, mpos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
            if (arr[j] > arr[mpos])
            {
                mpos = j;
            }
        }
        swap(&arr[pos], &arr[mpos]);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(arr[i] - i + 1);
    }
    cout << sum << endl;
}