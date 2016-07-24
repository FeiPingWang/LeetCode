class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        vector<int> tmp;
        vector<int> visited(nums.size(),0);
        sort(nums.begin(),nums.end());  //sorted
        FindRes(res,tmp,nums,visited);
        return res;
    }
    
    void FindRes(vector<vector<int>>& res,vector<int>& tmp,vector<int>& nums,vector<int> visited)
    {
        if(tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0;i < nums.size();i++)
        {
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])    //三种情况很难搞(!visited[i-1] 意思是要按照
                continue;                   //如果第一个重复元素前面的元素还没在当前结果中，那么我们不需要进行递归
            if(!visited[i])                                        //也适用于没有相同元素的情况下，注意
            {
                visited[i] = 1;
                tmp.push_back(nums[i]);
                FindRes(res,tmp,nums,visited);
                visited[i] = 0;
                tmp.pop_back();
            }
        }
    }
};