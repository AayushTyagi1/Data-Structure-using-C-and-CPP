class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1)
            return "";
        int i=0;
        for(;i<n;i++)
        {
            if(palindrome[i]!='a' && i!=n/2)
            {
                palindrome[i]='a';
                break;
            }
        }
        if(i==n)
            palindrome[i-1]='b';
        return palindrome;
    }
};