#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int ceil(vector<int> lis, int l, int r, int key)
    {
        while (r > l)
        {
            int m = l + (r - l) / 2;
            if (lis[m] >= key)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis;
        int l = 1;
        lis.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > lis[l - 1])
            {
                lis.push_back(nums[i]);
                l++;
            }

            else
            {
                int t = ceil(lis, 0, l - 1, nums[i]);
                lis[t] = nums[i];
            }
        }
        return l;
    }
};
int main()
{
    Solution obj;
    vector<int> a = {3, 4, 2, 8, 10};
    cout << obj.lengthOfLIS(a);
}