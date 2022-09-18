class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int left[n], right[n];
        int l=0, r=0;
        for(int i=0;i<n;i++)
        {
            l=max(l, height[i]);
            left[i]=l-height[i];
            
        }
        for(int i=n-1;i>=0;i--)
        {
            r=max(r, height[i]);
            right[i]=r-height[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i], right[i]);
        }
        return ans;
    }
};