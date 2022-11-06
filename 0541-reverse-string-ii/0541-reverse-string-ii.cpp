class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.length()<k){
            reverse(s.begin(), s.end());
            return s;
        }
        int len = s.length();
        int l=0, r=k;
        while(l<s.length()+k)
        {
            int mini = min(r, len);
            reverse(s.begin()+l, s.begin()+mini);
            l+=2*k;
            r+=2*k;
        }
        return s;
    }
};