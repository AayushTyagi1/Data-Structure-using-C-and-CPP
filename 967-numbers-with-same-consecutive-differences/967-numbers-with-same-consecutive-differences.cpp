// Time Complexity: O(2 ^ n)
// Space Complexity: O(2 ^ n)
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i=1;i<=9;i++)
            q.push(i);
        while(--n)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int p=q.front();
                q.pop();
                for(int j=0;j<10;j++)
                {
                    if(abs(p%10-j)==k)
                    {
                        q.push(p*10+j);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
            ans.push_back(q.front()), q.pop();
        return ans;
    }
};