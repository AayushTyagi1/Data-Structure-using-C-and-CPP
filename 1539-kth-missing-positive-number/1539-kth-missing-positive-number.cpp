class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int missingIndex=0;
        for(int i=0;i<arr.size();)
        {
            if(arr[i]==num)
            {
                num++;
                i++;
            }
            else
            {
                missingIndex++;
                if(missingIndex==k)
                return num;
                 num++;
            }
        }
        return num+k-missingIndex-1;
    }
};