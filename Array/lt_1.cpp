class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ht;
        vector<int> vectorRes;
        if(nums.size() == 0)
            return vectorRes;
        for(int i=0;i<nums.size();i++)
        {
            auto it = ht.find(target-nums[i]);
            if( it != ht.end())
            {
                vectorRes.push_back(i);
                vectorRes.push_back(it->second);
                break;
            }
            if(ht[nums[i]] == 0)    //使用hashtable时需要注意前后相同的元素会覆盖second的值，需特别处理
                ht[nums[i]] = i;
        }
        sort(vectorRes.begin(),vectorRes.end());
        return vectorRes;
    }
};