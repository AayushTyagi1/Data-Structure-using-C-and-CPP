#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int p1 = 0;
        sort(nums.begin(), nums.end());
        int p2 = 1;
        int res = 0;
        set<pair<int, int>> s;
        while (p1 < nums.size() && p2 < nums.size())
        {
            if (p1 != p2 && abs(nums[p2] - nums[p1]) == k && s.find({nums[p1], nums[p2]}) == s.end())
            {
                s.insert({nums[p1], nums[p2]});
                res++;
            }
            if (abs(nums[p2] - nums[p1]) > k)
                p1++;
            else
                p2++;
        }
        return res;
    }
};

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5};
    int k = 2;
    Solution s;
    cout << s.findPairs(arr, k);
}