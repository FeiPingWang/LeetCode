class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 1)
			return 0;
		int gMax = nums[0];
		int cur_Max = nums[0];
		int cur_Min = nums[0];
		
		for(int i = 1;i<nums.size();i++)
		{
			int a = cur_Max * nums[i];
			int b = cur_Min * nums[i];
			cur_Max = max(max(a,b),nums[i]);
			cur_Min = min(min(a,b),nums[i]);
			gMax = max(gMax,cur_Max);
		}
		return gMax;
		
    }
};