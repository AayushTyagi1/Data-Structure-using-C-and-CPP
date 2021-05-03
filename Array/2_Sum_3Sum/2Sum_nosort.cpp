//Return Indices
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int comp = target - nums[i];
        if (mp.count(comp))
        {
            return {i, mp[comp]};
        }
        mp[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> arr = {5, 3, 1, 6, 8, 4, -3, 7, 2, 6};
    int k = 11;
    vector<int> v = twoSum(arr, k);
    cout << v[0] << " " << v[1];
}