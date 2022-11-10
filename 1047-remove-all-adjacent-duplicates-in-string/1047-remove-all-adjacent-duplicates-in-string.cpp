class Solution {
public:
    string removeDuplicates(string s) {
        //First approach Delete
        //Time complexity O(N^2) as s.erase has O(N) complexity in itself
        int l = s.length()-1;
        for(int i=0; i<l;i++)
        {
            if(i<0)
                continue;
            if(s[i]==s[i+1]) {
                s.erase(i, 2);
                i-=2;
                l=s.length()-1;
            }
        }
        return s;
    }
};