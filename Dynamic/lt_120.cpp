#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
			return 0;
		if(triangle.size() == 1)
		    return triangle[0][0];
		    
		int row = triangle.size()-1;
		//int col = triangle[row].size()-1;
		vector<vector<int>> F;
		for(int i = 0;i <= row;i++)
		{
			vector<int> tmp(i+1,9999);
			F.push_back(tmp);
			for(int j = 0;j < i+1;j++)
			{
			    int num = triangle[i][j];
			    if(i == 0 && j == 0)
			        F[i][j] = num;
				else if(j == 0)
					F[i][j] = F[i-1][j]+num;
				else if(j == i)
					F[i][j] = F[i-1][j-1]+num;
				else
				    F[i][j] = min(F[i-1][j],F[i-1][j-1])+num;
			}
		}
		int res = 9999;
		for(int i = 0;i <= row;i++)
		{
			if(F[row][i] < res)
				res = F[row][i];
		}
		return res;
		
    }
};

int main(void)
{
	vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,2,6,7}};
	Solution s;
	cout << s.minimumTotal(triangle);
	return 0;
	
}