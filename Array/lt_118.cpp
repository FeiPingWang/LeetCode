//Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        if(numRows < 1)
            return res;
        for(int i = 1;i <= numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 1;j < i-1; j++)
            {
                tmp.push_back(res[i-2][j-1] + res[i-2][j]);
            }
            if(i != 1)
                tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
    
};