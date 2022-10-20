class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> m = {{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},
                                      {7,"VII"},{8,"VIII"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},
                                      {90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string ans = "";
        int i = m.size()-1;
        while(num>0 and i>=0)
        {
            if(num>=m[i].first)
            {
                ans+=m[i].second;
                num-=m[i].first;                
            }
            else
                --i;
        }
        return ans;
    }
};