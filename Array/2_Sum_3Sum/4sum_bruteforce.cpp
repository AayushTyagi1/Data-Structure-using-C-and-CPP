class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 4)
        {
            return result;
        }
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < N - 3)
        {
            int j = i + 1;
            while (j < N - 2)
            {
                int k = j + 1;
                while (k < N - 1)
                {
                    int find = target - (nums[i] + nums[j] + nums[k]);
                    if (binary_search(nums.begin() + k + 1, nums.end(), find))
                    {
                        result.push_back({nums[i], nums[j], nums[k], find});
                    }
                    k++;
                    while (k < N - 1 && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                }
                j++;
                while (j < N - 2 && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }
            i++;
            while (i < N - 3 && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return result;
    }
};