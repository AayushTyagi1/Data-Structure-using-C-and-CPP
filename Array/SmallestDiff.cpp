#include <bits/stdc++.h>

using namespace std;

int SmallesDiff(vector<int> arr, vector<int> arr2)
{
    int n1 = arr.size();
    int n2 = arr2.size();
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    int min = abs(arr2[0] - arr[0]);
    int i = 0, j = 0;
    while (i < n1 || j < n2)
    {
        if (arr[i] == arr2[j])
        {
            return 0;
        }
        else if (arr[i] < arr2[j])
        {
            if (abs(arr2[j] - arr[i]) < min)
            {
                min = abs(arr2[j] - arr[i]);
            }
            i++;
        }
        else
        {
            if (abs(arr2[j] - arr[i]) < min)
            {
                min = abs(arr2[j] - arr[i]);
            }
            j++;
        }
    }
    return min;
}

/*
int SmallesDiff(vector<int> arr, vector<int> arr2)
{
    int n1 = arr.size();
    int n2 = arr2.size();
    int min = 9999999;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (abs(arr[i] - arr2[j]) < min)
            {
                min = abs(arr[i] - arr2[j]);
            }
        }
    }
    return min;
}
*/
int main()
{
    vector<int> arr = {-1, 5, 10, 28, 20, 3};
    vector<int> arr2 = {26, 134, 135, 15, 17};
    cout << SmallesDiff(arr, arr2);
}