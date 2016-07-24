class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(s < 0 || nums.size() == 0)
            return 0;
        int sum = nums[0];		//********
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        while(r < nums.size())
        {
            if(sum >= s)
            {
                if(r-l+1 < res)
                    res = r-l+1;
                sum -= nums[l++];
                continue;
            }
            else
                sum += nums[++r];
        }
        if(l == 0)
            return 0;
        return res;
    }
};