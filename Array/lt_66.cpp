class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int flag=0;
        for(int i = digits.size()-1;i>=0;i--)
        {
            int sum = 0;
            if(i == digits.size()-1)
                sum = digits[i] + flag + 1;
            else
                sum = digits[i] + flag;
           
            if(sum >= 10)
            {
                digits[i] = sum - 10;
                flag = 1;
            }
            else
            {
                digits[i] = sum;
                flag = 0;
            }
        }
        if(flag == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};