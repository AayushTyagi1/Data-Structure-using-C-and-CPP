#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    int i = 0, j = n;
    vector<int> ans;
    sort(nums.begin(), nums.end());

    while (i < n && j > 0)
    {
        if (nums[i] + nums[j] == target)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }

        else if (nums[i] + nums[j] < target)
            i++;

        else
            j--;
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 3, 1, 6, 8, 4, -3, 7, 2, 6};
    int k = 11;
    vector<int> v = twoSum(arr, k);
    cout << v[0] << " " << v[1];
}