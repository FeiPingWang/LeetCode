class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> res;
        if(k < 1 || nums.size() <= 0)
            return false;
        for(int i =0;i<nums.size();i++)
        {
            if(res.find(nums[i]) != res.end() && i-res[nums[i]] <= k)
                return true;
            else
                res[nums[i]] = i;
        }
        return false;
            
    }
};