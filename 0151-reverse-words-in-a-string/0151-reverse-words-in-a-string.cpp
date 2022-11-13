class Solution {
public:
    string removeMultipleSpaces(string s)
    {
        int i, len, start, end;
        for (i = 0; i < s.size() && ' ' == s[i]; i++);
        start = i;
        for (i = s.size() - 1; i >= 0 && ' ' == s[i]; i--);
        end = i;
        for (i = start, len = 0; i <= end; i++) {
            if (' ' == s[i] && ' ' == s[i - 1])
            continue;
             s[len++] = s[i];
          }
         s.erase(s.begin() + len, s.end());
        return s;
    }
    
    string reverseWords(string s) {
        s = removeMultipleSpaces(s);
        int start=0, n=s.length();
        string ans="";
        for(int end=0;end<n;end++)
        {
            if(s[end]==' ')
            {
                reverse(s.begin()+start, s.begin()+end);
                start=end+1;
            }
        }
        reverse(s.begin()+start, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};