class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        map<int,int> visited;
        vector<int> tmp;
        FindRes(res,tmp,nums,visited);
        return res;
    }
    
    void FindRes(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,map<int,int> visited)
    {
        if(tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0;i < nums.size();i++)
        {
            if(visited[nums[i]] == 0)
            {
                visited[nums[i]] = 1;
                tmp.push_back(nums[i]);
                FindRes(res,tmp,nums,visited);   //关键是要把解空间在还原回去！！！
                visited[nums[i]] = 0;
                tmp.pop_back();
            }
        }
    }
};