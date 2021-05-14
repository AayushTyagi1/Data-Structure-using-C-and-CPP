class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 1)
            return 0;

        vector<int> p;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
            {
                p.push_back(i);
            }
        }
        int ans = 0;
        for (auto it = p.begin(); it != p.end(); it++)
        {
            int i = *it;
            int l = 3;
            int b = i - 1;
            int f = i + 1;
            while (b > 0 && arr[b - 1] < arr[b])
            {
                l++;
                b--;
            }
            while (f < n - 1 && arr[f] > arr[f + 1])
            {
                l++;
                f++;
            }
            if (ans < l)
                ans = l;
        }
        return ans;
    }
};