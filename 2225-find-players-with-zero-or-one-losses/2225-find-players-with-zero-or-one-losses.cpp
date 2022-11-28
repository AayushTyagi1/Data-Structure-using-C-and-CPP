class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpwin, mplose;
        vector<int> zero, one;
        for(int i=0;i<matches.size();i++)
        {
            mplose[matches[i][1]]++;
        }
        for(int i=0;i<matches.size();i++)
        {
            if(mplose.find(matches[i][0])==mplose.end())
            {
                zero.push_back(matches[i][0]);
                mplose[matches[i][0]]=2;
            }
        }
        for(auto i: mplose)
        {
            if(i.second==1)
                one.push_back(i.first);
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        vector<vector<int>> ans;
        ans.push_back(zero);
        ans.push_back(one);
        return ans;
    }
};