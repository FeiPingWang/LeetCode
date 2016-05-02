class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        sort(citations.begin(),citations.end());
        unordered_map<int,int> mp;
        int max= 0;
        int len = citations.size();
        for(int i = 0;i < len;i++)
        {
            if(mp.find(citations[i]) == mp.end() || mp[citations[i]] > citations[i])
                mp[citations[i]] = len-i;
            //else if(mp[citations[i]] > len-i)
        }
        for(auto it = mp.begin();it != mp.end();it++)
        {
            if(it->first >= it->second)
                if(max < it->second)
                    max = it->second;
        }
        return max;
    }
};