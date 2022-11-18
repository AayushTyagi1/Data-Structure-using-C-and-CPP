class Solution {
public:
    bool isUgly(int num) {
        if(num==0)
            return false;
        vector<int> a = {2, 3, 5};
        int i=0;
        while(i<3){
            if(num%a[i]==0)
              num/=a[i];
            else
                i++;
        }
        return num == 1;
    }
};