class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans="";
        string aux;
        while(getline(ss, aux, ' '))
        {
            if(ans!="")
                ans+=" ";
            reverse(aux.begin(), aux.end());
            ans=ans+aux;
        }
        return ans;
    }
};