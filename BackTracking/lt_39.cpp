class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        FindTarget(res,tmp,candidates,target,0);
        return res;
        
    }
    void FindTarget(vector<vector<int>>& res, vector<int> tmp, vector<int>& candidates, int target, int cur)
	{
		for (int i = cur; i < candidates.size(); i++)
		{
			if (candidates[i] == target)
			{
				tmp.push_back(candidates[i]);
				res.push_back(tmp);
				return;
			}
			if (candidates[i] < target)
			{
				tmp.push_back(candidates[i]);
				FindTarget(res, tmp, candidates, target - candidates[i], i);
				tmp.pop_back();
			}
		}
	}
};