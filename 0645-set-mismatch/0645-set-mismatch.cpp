class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n=nums.size();
        vector<int> count(n+1, 0);
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(count[i]==2)
                ans[0]=i;
            if(count[i]==0)
                ans[1]=i;
        }
        return ans;
    }
};