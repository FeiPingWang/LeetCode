class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
			return 0;
		int len = data.size()-1;
		return findLastK(data,0,len,k) - findFirstK(data,0,len,k);
    }
	
	int findFirstK(vector<int>& data,int start,int end,int k)
	{
		while(start <= end)
		{
			int mid = start + (end-start)/2;
			if(data[mid] > k)
				end = mid-1;
			else if(data[mid] < k)
				start = mid+1;
			else if(data[mid] == k)
			{
				if((mid > 0 && data[mid-1] != k) || mid==0))
					return mid;
				else
					end = mid-1;
			}
		}
		return 0;
	}
	
	int findLastK(vector<int>& data,int start,int end,int k)
	{
		while(start <= end)
		{
			int mid = start + (end-start)/2;
			if(data[mid] > k)
				end = mid-1;
			else if(data[mid] < k)
				start = mid+1;
			else if(data[mid] == k)
			{
				if((mid < data.size()-1 && data[mid+1] != k) || mid==data.size()-1))
					return mid;
				else
					end = mid+1;
			}
		}
		return 0;
	}
};