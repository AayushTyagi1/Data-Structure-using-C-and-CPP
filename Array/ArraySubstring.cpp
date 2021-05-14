class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int pos = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                mini = min(mini, i);
                pos = 1;
                maxi = max(maxi, i + 1);
            }
        }
        if (pos == 0)
            return 0;
        int mine = INT_MAX, maxe = INT_MIN;

        for (int i = mini; i <= maxi; i++)
        {
            if (nums[i] < mine)
                mine = nums[i];
            if (nums[i] > maxe)
                maxe = nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > mine)
            {
                mini = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            //cout<<nums[i]<<">"<<maxe;
            if (nums[i] < maxe)
            {
                maxi = i;
                break;
            }
        }

        return maxi - mini + 1;
    }
};