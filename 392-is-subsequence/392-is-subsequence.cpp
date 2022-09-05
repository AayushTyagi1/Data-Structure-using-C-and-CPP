class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())
            return false;
        int i=0, j=0;
        while(t[i] && s[j])
        {
            if(s[j]==t[i])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if(j==s.length())
            return true;
        return false;
    }
};