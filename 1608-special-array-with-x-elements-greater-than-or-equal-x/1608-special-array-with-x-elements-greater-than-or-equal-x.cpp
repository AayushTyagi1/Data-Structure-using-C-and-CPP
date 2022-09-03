class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       for(int i=1;i<1000;i++)
       {
           int count=0;
           for(int j=0;j<n;j++)
               if(nums[j]>=i)
               {
                   count+=n-j;
                   break;
               }
           if(i==count)
               return i;
       }
        return -1;
    }
};