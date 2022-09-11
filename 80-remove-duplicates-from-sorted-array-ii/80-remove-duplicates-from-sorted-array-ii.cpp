class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curElement = nums[0];
        int ind=1;
        int freq=1;
        for(int i=1;i<nums.size();i++)
        {
            if(curElement==nums[i])
            {
                freq++;
                if(freq>=3)
                {
                    continue;
                }
                else
                    nums[ind++]=nums[i];
            }
            else
            {
                freq=1;
                curElement=nums[i];
                nums[ind++]=nums[i];
            }
        }
        return ind;
    }
};