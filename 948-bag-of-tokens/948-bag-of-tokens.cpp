class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size()-1;
        int score=0, ans=0;
        while(l<=r && (power>=tokens[l] || score>0))
        {
            while(l<=r && power>=tokens[l])
            {
                power-=tokens[l];
                l++;
                score++;
            }
            ans = max(score, ans);
            if(l<=r && score>0) {
                power+=tokens[r];
                score--;
                r--;
            }
        }
        return ans;
    }
};