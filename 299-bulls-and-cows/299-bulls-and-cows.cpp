#include <cstdlib>
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int i=0;
        int freq[10]={0};
        while(secret[i])
        {
            if(secret[i]==guess[i]){
                bulls++;
                guess[i]='A';
            }
            else 
                freq[secret[i]-'0']++;
            i++;
        }
        i=0;
         while(guess[i])
        {
            
           if(guess[i]!='A' && freq[guess[i]-'0']>0)
           {
               cows++;
               freq[guess[i]-'0']--;
           }
            i++;
        }
        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};