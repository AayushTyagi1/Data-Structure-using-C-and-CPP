class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        for(auto i: nums)
            mp[i]++;
           
        for(auto i: mp)
        {
            if(s.find(i.second)!=s.end())
                return false;
            else
                s.insert(i.second);
        }
        return true;
    }
};