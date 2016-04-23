class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size() < 3)
            return res;
        for(int i = 0;i< nums.size()-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])   //跳过重复元素关键
                continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0)                    //跳过重复元素关键
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(++left < right && nums[left] == nums[left-1]);    //跳过重复元素
                    while(--right < left && nums[right] == nums[right+1]);
                    continue;
                }
                else if(sum < 0)
                    left ++;
                else
                    right--;
            }
                
        }
        return res;
    }
};