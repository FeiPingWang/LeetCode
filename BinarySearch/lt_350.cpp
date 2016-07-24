class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++)
        {
            if(nums1.size() != 0)
            {
                if(Search(nums1,nums2[i]) == true)
                    res.push_back(nums2[i]);
            }
            else
                return res;
        }
        return res;
    }
    
    bool Search(vector<int>& nums,int k)
    {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            if(nums[m] == k)
            {
                nums.erase(nums.begin()+m);
                return true;
            }
            else if(nums[m] < k)
                l = m+1;
            else
                r = m-1;
        }
        return false;
    }
};