class Solution {
public:
    string removeDuplicates(string s) {
        //Simple Two pointer approach
        //Time complexity O(N)
        int i=0;
        int l = 0, r = s.length();
        while(i<r)
        {
            s[l] = s[i];
            if (l > 0 && s[l - 1] == s[l])
                l -= 2;
            i++;l++;
        }
        return s.substr(0, l);
    }
};

/*

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
    
*/