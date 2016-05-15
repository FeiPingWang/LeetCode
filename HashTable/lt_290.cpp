class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(str.size() == 0 || pattern.size() == 0)
            return false;
        
        unordered_map<char,string> mp1;  
        unordered_map<string,char> mp2;
        unordered_map<char,string>::iterator iter1; 
        unordered_map<string,char>::iterator iter2;
        vector<string> vs;
        stringstream ss(str);
        string tmp;
        while(getline(ss,tmp,' '))
            vs.push_back(tmp);
        if(pattern.size() != vs.size())
            return false;
        for(int i = 0; i < pattern.size();i++)
        {
            if((iter1 = mp1.find(pattern[i])) != mp1.end())
            {
                if(iter1->second != vs[i]) 
                    return false;
            }
            else if((iter2 = mp2.find(vs[i])) != mp2.end())
            {
                if(iter2->second != pattern[i])
                    return false;
            }
            else
            {
                mp1.insert({pattern[i],vs[i]});
                mp2.insert({vs[i],pattern[i]});
            }
        }
        return true;
    }
};