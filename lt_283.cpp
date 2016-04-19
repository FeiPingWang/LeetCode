class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        int n = 0;
        int tmp = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0 && tmp == -1)
            {
                tmp = i;
                n++;
            }
            if(nums[i] != 0 && tmp != -1)
            {
                int t = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = t;
                tmp++;
            }
        }
    }
};