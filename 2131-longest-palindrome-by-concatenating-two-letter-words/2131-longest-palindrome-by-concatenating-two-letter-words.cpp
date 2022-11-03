class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = 0;
        int countOdd=0;
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
                if(mp.find(s)!=mp.end() && mp[s]>0)
                {
                    if(s[0]==s[1])
                        countOdd--;
                    if(mp[s]>=1)
                    {
                        len+=4;
                        mp[s]--;
                    }
                    
                }
                else
                {
                    if(s[0]==s[1])
                        countOdd++;
                    string rev = "";
                    rev+=s[1];
                    rev+=s[0];
                    mp[rev]++;
                }
        }
       if(countOdd>0){
           len+=2;
       }
        return len;
    }
};