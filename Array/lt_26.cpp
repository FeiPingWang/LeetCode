class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=0;
        if(nums.size() == 0)
            return nums.size();
        for(int i=0;i < nums.size();i++)
        {
            if(nums[n] != nums[i])
            {
                nums[n+1] = nums[i];
                n++;
            }
        }
        return n+1;
    }
};