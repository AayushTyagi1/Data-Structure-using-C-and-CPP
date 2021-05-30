#include <bits/stdc++.h>

using namespace std;
void countDistinct(int arr[], int n, int k)
{
    unordered_set<int> h(arr, arr + k);
    cout << h.size() << " ";
    for (int i = k; i < n; i++)
    {
        cout << "D" << arr[i - k];
        h.erase(arr[i - k]);
        h.insert(arr[i]);
        cout << h.size() << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    countDistinct(arr, 7, k);
}