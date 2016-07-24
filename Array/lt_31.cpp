class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-1;i >= 1;i--)
        {
            if(nums[i] > nums[i-1])
                break;
        }
        if(i == 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int l = i-1;
        int r = nums.size()-1;
        while(nums[l]>=nums[r])r--;
            swap(nums[l],nums[r]);
        reverse(nums.begin()+l+1,nums.end());
    }
};