class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n==0)
            return 0;
        for(int i=0;i<n-1;i++)
        {
            if(i<0)
                continue;
            if(s[i]==s[i+1]+32 || s[i]==s[i+1]-32)
            {
                s.erase(i, 2);
                i-=2;
            }
        }
        return s;
    }
};