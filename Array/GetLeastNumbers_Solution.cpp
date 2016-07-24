#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
       	if(k <= 0)
            return vector<int>();
		priority_queue<int> pq;
		vector<int> res;
        for(int i = 0;i<input.size();i++)
    	{
            if(pq.size() < k)
				pq.push(input[i]);
			else{
				int tmp = pq.top();
				if(input[i] < tmp)
				{
					pq.pop();
					pq.push(input[i]);
				}
			}
        }
		while(!pq.empty())
		{
			int tmp = pq.top();
			pq.pop();
			res.push_back(tmp);
		}
		reverse(res.begin(),res.end());
		return res;
		
		
    }
};

int main(void)
{
	Solution s;
	vector<int> vvv={1,4,5,6,2,7,3,8};
	vector<int> v = s.GetLeastNumbers_Solution(vvv,4);
	for(auto &c : v)
		cout << c << " ";
	cout << endl;
	return 0;
}

