class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        
        for(int i = 0; i < nums.size(); i++) {
            if(s.count(nums[i])) {
                return true;
            } else {
                s.insert(nums[i]);
            }
            
            if(i >= k) {
                s.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};