class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        int sum = 0;
        vector<int> v;
        while(1)
        {  
            sum = 0;
            while(n > 0)
            {
                int bit = n % 10;
                sum += bit * bit;
                n /= 10; 
            }
            if(find(v.begin(),v.end(),sum) != v.end())
                return false;
            else
                v.push_back(sum);
            if(sum == 1)
                return true;
            n = sum;
        }
        return false;
    }
};