// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
// My 0ms C++ solution 
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isBadVersion(mid) == true)
            {
                 if(mid <= 1)
                    break;
                 if(isBadVersion(mid-1) == false)       //if don't do this step will be 1ms
                    return mid;
                 high = mid-1;
            }
            else
                low = mid +1;
        }
        return low;
    }
};