vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    int i, n = nums.size(), j, k;

    sort(nums.begin(), nums.end());

    for (i = 0; i < n - 1; i++)
    {
        int sum = -nums[i];
        j = i + 1;
        k = n - 1;
        if (i == 0 || nums[i] != nums[i - 1])
        {
            while (j < k)
            {
                if (nums[j] + nums[k] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);

                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (k > j && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > sum)
                {
                    k--;
                }
                else
                    j++;
            }
        }
    }

    return ans;
}