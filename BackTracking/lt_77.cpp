class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visit(n,false);
        Find(res,tmp,visit,n,k,0);
        return res;
    }
    
    void Find(vector<vector<int>>& res,vector<int>& tmp,vector<bool>& visit,int n,int k,int cur)
    {
        if(tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = cur+1;i <= n;i++)
        {
            if(!visit[i])
            {
                visit[i] = true;
                tmp.push_back(i);
                Find(res,tmp,visit,n,k,i);
                visit[i] = false;
                tmp.pop_back();
            }
        }
    }
};