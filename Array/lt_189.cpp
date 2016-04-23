//Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k < 0 )
            return;
        if(k > nums.size())
            k = k % nums.size();
        int n = 0;
        int len = nums.size() - k;
        while(n < len) 
            nums.push_back(nums[n++]);
        nums.erase(nums.begin(),nums.begin()+n);
        
    }
};