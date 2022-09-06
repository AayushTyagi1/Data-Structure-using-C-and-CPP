class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=0;
        for(int i =1;i<intervals.size();i++)
        {
            if(intervals[start][1] >= intervals[i][0])
            {
                intervals[start][0] = min(intervals[start][0],intervals[i][0]);
                intervals[start][1] = max(intervals[start][1],intervals[i][1]);
            }
            else
            {
                start++;
                intervals[start] = intervals[i];
                
            }
                
        }
        while(start+1 != intervals.size())
        {
            intervals.pop_back();
        }
        return intervals;
    }
};