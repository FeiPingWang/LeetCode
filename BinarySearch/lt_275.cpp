class Solution {
public:
    //ascending排序的情况
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        int max = 0;
        int MAX = 0;
        int l = 0;
        int h = citations.size();
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(citations[mid] <= (citations.size() - mid))
            {
                l = mid+1;
                if(max < citations[mid])
                    max = citations[mid];
            }
            else if(citations[mid] > (citations.size() - mid))
            {
                h = mid - 1;
                MAX = citations.size()-mid;                     //important
            }
        }
        return max >= MAX ? max : MAX;
    }
};