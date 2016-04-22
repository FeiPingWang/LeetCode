//Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {    //二分法来做
        int left = 0;
        int min = INT_MAX;
        int high = nums.size()-1;
        if(nums[left] <= nums[high])
            return nums[left];
        while(left <= high)
        {
            int mid = (left + high) / 2;
            if(nums[mid] >= nums[left])  //左边有序
            {
                if(nums[left] < min)
                    min = nums[left];
                left = mid + 1;
            }
            else                        //右边有序
            {
                if(nums[mid+1] < min)
                    min = nums[mid+1];
                high = mid;
            }
        }
        return min;
    }
};