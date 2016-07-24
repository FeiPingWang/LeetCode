class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
			return false;
		int r = 0;
		int c = matrix[0].size()-1;
		bool res = false;
		while(r < matrix.size() && c >= 0)
		{
			if(matrix[r][l] >　target)
				l--;
			else if(matrix[r][l] < target)
				r++;
			else
			{
				res = true;
				break;
			}
		}
		return res;
    }
};