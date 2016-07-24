class Solution {
public:
    /*  突破点是先排序  */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> tmp;
        unordered_map<string,int> mp;
        unordered_map<string,int>::iterator iter;
        int num = 0;
        for(int i = 0; i < (int)strs.size(); i++)
        {
            string aa = strs[i];
            sort(strs[i].begin(),strs[i].end()); //sort
            if((iter = mp.find(strs[i])) != mp.end())
            {
                int m = iter->second;
                res[m].push_back(aa);
            }
            else
            {
                mp[strs[i]] = num;  //插入
                res.push_back(vector<string>(0,""));
                res[num].push_back(aa);
                num++;
            }
        }
        for(int i = 0;i<res.size();i++)
            sort(res[i].begin(),res[i].end());
        return res;
    }
};