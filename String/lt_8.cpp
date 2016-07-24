/*这题考虑到所有的情况比较困难(need review)*/
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() <= 0)
            return 0;
        int flag = 1;
        int len = str.size();
        int sum = 0,i;
        for(i = 0; str[i] == ' '; ++ i);
        if(str[i] == '+')
        {
            i++;
            flag = 1;
        }
        else if(str[i] == '-')
        {
            flag = -1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')  //不合法的情况
        {
            int bit = str[i++] - '0';          //当前位
            if(sum > (INT_MAX-bit)/10)
                return flag == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + bit;
        }
        return flag * sum;
    }
};