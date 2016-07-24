class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int res1 = 0;
        int res2 = 0;
        int result = 0;
        int tmp = 0;
        int bit = 0;
        if(nums.size() == 0)
            return res;
        for(int i = 0;i<nums.size();i++)    //O(n)
            tmp ^= nums[i];
        for(int i = 0;i<32;i++)
        {
            if(tmp & (1 << i))
            {
                bit = i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] &(1<<bit))
                res1 ^= nums[i];
            else
                res2 ^= nums[i];
        }
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};