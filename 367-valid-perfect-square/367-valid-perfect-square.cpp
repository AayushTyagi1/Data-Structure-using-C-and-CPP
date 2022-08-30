class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return 1;
        int left = 1, right = num;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(mid*1.0 == num*1.0/mid*1.0)
                return true;
            else if (mid*1.0 > num*1.0/mid*1.0)
                right = mid - 1;
            else
                left = mid + 1;
                
        }
        return false;
    }
};