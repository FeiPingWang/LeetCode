class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return string();
        string res = "1";
        int j = 1;
        while(j++ < n)
            res = helper(res);
        return res;
    }
    
    string helper(string str)
    {
        char pre = str[0];
        int count = 1;
        string res;
        for(int i = 1; i < str.size();i++)
        {
            if(str[i] == pre)
                count++;
            else
            {
                char tmp = count + '0';
                res = res + tmp + pre;
                pre = str[i];
                count = 1;
            }
        }
        //最后一个
        char tmp = count + '0';
        res = res + tmp + pre;
        return res;
    }
};