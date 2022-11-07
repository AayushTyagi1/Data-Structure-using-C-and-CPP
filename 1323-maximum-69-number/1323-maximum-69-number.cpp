class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int pos=-1, index=0;
        while(temp)
        {
            if(temp%10==6)
                pos=index;
            temp/=10;
            index++;
        }
        if(pos!=-1)
            num+=pow(10, pos)*3;

        return num;
    }
};