class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        int n = arr.size();
        if (n < 4)
            return ans;
        int i, j, k;
        sort(arr.begin(), arr.end());
        for (i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i - 1] == arr[i])
                continue;
            if (arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] > target)
                break;
            if (arr[i] + arr[n - 3] + arr[n - 2] + arr[n - 1] < target)
                continue;
            for (j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j - 1] == arr[j])
                    continue;
                if (arr[i] + arr[j] + arr[j + 1] + arr[j + 2] > target)
                    break;
                if (arr[i] + arr[j] + arr[n - 2] + arr[n - 1] < target)
                    continue;
                int L = j + 1;
                int R = n - 1;
                int check = target - arr[i] - arr[j];
                while (L < R)
                {
                    if (check < arr[L] + arr[R])
                    {
                        R--;
                        while (R - 1 > L && arr[R] == arr[R + 1])
                            R--;
                    }
                    else if (check > arr[L] + arr[R])
                    {
                        L++;
                        while (L + 1 < R && arr[L] == arr[L - 1])
                            L++;
                    }
                    else
                    {
                        ans.push_back({arr[i], arr[j], arr[L], arr[R]});
                        do
                            L++;
                        while (L < R && arr[L - 1] == arr[L]);
                        do
                            R--;
                        while (L < R && arr[R + 1] == arr[R]);
                    }
                }
            }
        }
        return ans;
    }
};