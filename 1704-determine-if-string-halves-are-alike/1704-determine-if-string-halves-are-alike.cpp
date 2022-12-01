class Solution {
public:
    bool halvesAreAlike(string s) {
        int l = 0, r = 0;
        
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
            l += isVowel(s[i]);
            r += isVowel(s[j]);
        }
        
        return l == r;
    }
    
    bool isVowel(char ch) {
        ch=tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};