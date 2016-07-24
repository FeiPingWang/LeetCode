class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        if(a.size() <= 0 || b.size() <= 0)
            return res;
        int lenMin = a.size() > b.size() ? b.size() : a.size();
        int flag = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        for(int i=0;i<lenMin;i++)
        {
            int bit = a[i] - '0' + b[i] -'0' + flag;
            if(bit >= 2)
            {
                bit = bit - 2;
                flag = 1;
            }
            else
                flag = 0;
            char c = '0'+ bit;
            res += c;
        }
        
        if(lenMin == a.size()) //a结束了
        {
            for(int i = lenMin;i<b.size();i++)
            {
                int bit = b[i] - '0' + flag;
                if(bit >= 2)
                {
                    bit -= 2;
                    flag = 1;
                }
                else
                    flag = 0;
                char c = '0'+ bit;
                res += c;
            }
        }
        else
        {
            for(int i = lenMin;i<a.size();i++)
            {
                int bit = a[i] - '0' + flag;
                if(bit >= 2)
                {
                    bit -= 2;
                    flag = 1;
                }
                else
                    flag = 0;
                char c = '0'+ bit;
                res += c;
            }
        }
        if(flag == 1)
            res+= '1';
        reverse(res.begin(),res.end());
        return res;
    }
};