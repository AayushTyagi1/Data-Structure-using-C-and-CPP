class Solution {
public:
    bool isVowel(char c)
    {
        c=tolower(c);
        if(c=='a' || c=='e' || c== 'i' || c=='o' || c=='u')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int l = 0, r=s.length()-1;
        while(l<r)
        {
            bool v1 = isVowel(s[l]), v2 = isVowel(s[r]);
            if(v1 && v2)
            {
                swap(s[l], s[r]);
                l++;r--;
            }
            else if(v1)
            {
                r--;
            }
            else if(v2)
            {
                l++;
            }
            else{
                l++;r--;
            }
        }
        return s;
    }
};