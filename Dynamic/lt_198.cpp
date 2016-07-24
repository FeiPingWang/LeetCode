class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> F(nums.size(),-1);
        if(nums.size() < 2)
            return nums[0];
        F[0] = nums[0];
        F[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            F[i] = max(F[i-1],F[i-2]+nums[i]);
        }
        return F[nums.size()-1];
    }
};