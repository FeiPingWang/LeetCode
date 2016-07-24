class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() <= 1)
            return true;
        int l = 0;
        int r = s.size()-1;
        while(l < r)
        {
            if(!isalpha(s[l]) && !isalnum(s[l]))
            {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isalnum(s[r]))
            {
                r--;
                continue;
            }   
            if(tolower(s[l]) != tolower(s[r]))    //切记大小写转换
                return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};