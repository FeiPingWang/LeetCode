class Solution {
public:
    /*Binary search*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        for(int i = 0;i< nums2.size();i++)
        {
            if(find(res.begin(),res.end(),nums2[i]) != res.end())
                continue;
            int l = 0;
            int r = nums1.size()-1;
            while(l <= r)
            {
                int m = l + (r-l)/2;
                if(nums1[m] == nums2[i])
                {
                    res.push_back(nums2[i]);
                    break;
                }
                else if(nums1[m] > nums2[i])
                    r = m-1;
                else
                    l = m + 1;
            }
        }
        return res;
    }
};


class Solution {
public:
    /*Hash Table*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]] == 0)
                mp[nums1[i]] = 1;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mp[nums2[i]] == 1)
            {
                res.push_back(nums2[i]);
                mp[nums2[i]] = 0;
            }
        }
        return res;
    }
};
