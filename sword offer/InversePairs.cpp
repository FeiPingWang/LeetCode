#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() < 1)
			return 0;
		int len = data.size()-1;
		return IncersePairsCore(data,0,len);
    }
	
	int IncersePairsCore(vector<int>& data,int start,int end)
	{
		int res = 0;
		if(start < end)
		{
			int mid = start + (end - start)/2;
			res += IncersePairsCore(data,start,mid);
			res += IncersePairsCore(data,mid+1,end);
			res += MergeCount(data,start,mid,end);
		}
		return res;
	}
	
	int MergeCount(vector<int>& data,int start,int mid,int end)
	{
		int count = 0;
		int lenL = mid - start + 1;
		int lenR = end - mid;
		int res = 0;
		vector<int> vL(lenL,0);
		vector<int> vR(lenR,0);
		
		for(int i = 0;i < lenL;i++)
			vL[i] = data[start+i];
		
		for(int j = 0;j < lenR;j++)
			vR[j] = data[mid+1+j];
		
		int l = lenL - 1;
		int r = lenR - 1;
		int cur = end;
		while(l >= 0 && r >= 0)
		{
			if(vL[l] > vR[r])
			{
				data[cur--] = vL[l--];
				res += r+1;		//逆序对
			}
			else
			{
				data[cur--] = vR[r--];
			}
		}
		while(l >= 0)
			data[cur--] = vL[l--];
		while(r >= 0 )
			data[cur--] = vR[r--];
		
		for(auto c : data)
			cout << c<< " ";
		cout << endl;
		return res;
	}
};

int main(void)
{
	vector<int> obj={7,5,6,4,3,2};
	Solution s;
	cout << s.InversePairs(obj) << endl;
	return 0;
}