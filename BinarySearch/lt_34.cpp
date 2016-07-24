class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() <= 0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            
            if(nums[m] == target)
            {
                if(m == 0)
                {
                    res.push_back(m);
                    break;
                }
                else
                {
                    if(nums[m-1] != target)
                    {
                        res.push_back(m);
                        break;
                    }
                    else if(nums[m-1] == target) 
                        r = m-1;
                }
            }
            else
            {
                if(nums[m] > target)
                    r = m-1;
                else
                    l = m+1;
            }
        }
        l = 0;
        r = nums.size()-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            
            if(nums[m] == target)
            {
                if(m == nums.size()-1)
                {
                    res.push_back(m);
                    break;
                }
                else
                {
                    if(nums[m+1] != target)
                    {
                        res.push_back(m);
                        break;
                    }
                    else if(nums[m+1] == target) 
                        l = m+1;
                }
            }
            else
            {
                if(nums[m] > target)
                    r = m-1;
                else
                    l = m+1;
            }
        }
        if(res.size() == 0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        sort(res.begin(),res.end());
        return res;
    }
};