class Solution {
public:
/*此题关键是保持一个全局最优解和局部最优解(Important)*/
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int globl = nums[0];
        int cur = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(cur >= 0)
                cur = cur+nums[i];
            else
                cur = nums[i];
            if(cur > globl)
                globl = cur;
        }
        return globl;
    }
};