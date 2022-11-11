class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1, i=1, r=nums.size();
        while(i<r)
        {
            if(nums[i]!=nums[l-1])
            {
                nums[l++]=nums[i++];
            }
            else
                i++;
        }
        return l;
    }
};