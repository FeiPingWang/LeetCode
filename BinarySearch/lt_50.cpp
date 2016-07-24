class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double res = 1.0;
        int exponent = n;
        int flag = 1;
        if(n < 0)
        {
            if(n == 0x80000000)
            {
                exponent = 0x7fffffff;
                res *= x;
            }
            else
                exponent = -n;
            flag = -1;
        }
        while(exponent > 0)
        {
            if(exponent & 1)
                res *= x;
            x *= x;
            exponent >>= 1;
        }
        if(flag == -1)
            return 1/res;
        return res;
        
    }
};
