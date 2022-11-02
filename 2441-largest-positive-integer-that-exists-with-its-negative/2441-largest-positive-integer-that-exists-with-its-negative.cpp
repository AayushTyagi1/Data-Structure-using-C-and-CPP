class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            for(int j=nums.size()-1;j>=0;j--)
                if(nums[i]+nums[j]==0) return nums[j];
        return -1;
    }
};