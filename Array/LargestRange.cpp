class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int L = 1, maxl = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] == nums[i])
                continue;
            if (nums[i + 1] == nums[i] + 1)
                L++;
            else
            {
                maxl = max(maxl, L);
                L = 1;
            }
        }
        maxl = max(maxl, L);
        return maxl;
    }
};