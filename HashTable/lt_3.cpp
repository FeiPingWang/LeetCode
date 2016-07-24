class Solution {
public:
//思想是2个指针，维持一个滑动的窗口，更新左右指针
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int mlen = 0;
        int l = 0,r=0,i=0;
        unordered_map<char,int> mp;
        while(r < s.size())
        {
            if(mp.find(s[r]) != mp.end())
            {
                l = max(l,mp[s[r]]+1);
            }
            /*if(mp[s[r]] > l)
                l = mp[s[r]]+1;*/
            mp[s[r]] = r;
            mlen = max(mlen,r-l+1);
            r++;
        }
        return mlen;
        
    }
};