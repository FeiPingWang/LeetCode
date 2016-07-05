class Solution {
public:
// (n^2) < x < ((n+1)^2)
// return n
    int mySqrt(int x) {
        if(x < 1)
            return 0;
        int left = 1;
        int right = 0x7fffffff;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(mid > x/mid)
            {
                right = mid-1;
            }
            else
            {
                if(mid+1 > x /(mid+1))
                    return mid;
                left = mid+1;
            }
            
            
        }
        return 0;
    }
};
