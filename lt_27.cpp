class Solution {
public:
    int removeElement(vector<int>& nums, int val) {     //此处是引用，结果会改变原容器
        if(nums.size() == 0)
            return 0;
        int start= -1, end = -1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == val && start == -1)
                start = i;
            if(nums[i] != val && start != -1 && end == -1)
                end = i;
        }
        if(start != -1 && end == -1)
            end = nums.size();
        if(start != -1 && end != -1)
            nums.erase(nums.begin()+start,nums.begin()+end);
        return nums.size();
    }
};