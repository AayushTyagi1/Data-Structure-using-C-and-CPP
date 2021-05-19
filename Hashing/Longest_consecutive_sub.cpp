class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        unordered_map<int, bool> mp(n);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            int L = 1;
            if (mp[nums[i]] != false)
            {
                mp[nums[i]] = false;
                int j = 1;
                while (mp.find(nums[i] - j) != mp.end())
                {
                    mp[nums[i] - j] = false;
                    L++;
                    j++;
                }
                j = 1;
                while (mp.find(nums[i] + j) != mp.end())
                {
                    mp[nums[i] + j] = false;
                    L++;
                    j++;
                }

                ans = max(ans, L);
            }
        }
        return ans;
    }
};