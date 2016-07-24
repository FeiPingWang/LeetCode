class Solution {
public:
	/*也是利用两个hashtable来解决此类问题*/
    bool isIsomorphic(string s, string t) {
        if(s == t)
            return true;
        unordered_map<char,char> mst;
        unordered_map<char,char> mts;
        if(s.size() != t.size())
            return false;
        for(int i = 0;i<s.size();i++)
        {
            if(mst.find(s[i]) != mst.end())
            {
                if(mst[s[i]] != t[i])
                    return false;
            }
            if(mts.find(t[i]) != mts.end())
            {
                if(mts[t[i]] != s[i])
                    return false;
            }
            else
            {
                mst.insert({s[i],t[i]});
                mts.insert({t[i],s[i]});
            }
        }
        return true;
    }
}; 
