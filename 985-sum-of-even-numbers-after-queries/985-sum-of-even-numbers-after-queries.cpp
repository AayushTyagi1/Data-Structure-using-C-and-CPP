class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumeven=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            sumeven+=(nums[i]%2==0)?nums[i]:0;
        for(int i=0;i<queries.size();i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if(nums[index]%2==0)
                sumeven-=nums[index];
            nums[index]+=val;
            if(nums[index]%2==0)
                sumeven+=nums[index];
            ans.push_back(sumeven);
        }
        return ans;
    }
};