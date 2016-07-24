/*recursive solution but Time Limited*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        if(grid.size() <= 0)
            return 0;
        return FindPath(grid,0,0,grid[0][0]);
    }
    
    int FindPath(vector<vector<int>>& grid,int i,int j,int sum)
    {
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return sum + grid[i][j];
        if(i == grid.size() || j == grid[0].size())
            return INT_MAX;
        sum += grid[i][j];
        return min(FindPath(grid,i+1,j,sum),FindPath(grid,i,j+1,sum));
    }
};

/*Dynamic Programming solution*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        if(grid.size() <= 0)
            return 0;
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(),-1));
        res[0][0] = grid[0][0];
        //res[0][1] = grid[0][0] + grid[0][1];
      //  res[1][0] = grid[0][0] + grid[1][0];
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(i >= 1 && j >= 1)
                    res[i][j] = min(res[i-1][j],res[i][j-1]) + grid[i][j];
                else if(i == 0 && j > 0)
                    res[i][j] = res[i][j-1]+grid[i][j];
                else if(i > 0 && j == 0)
                    res[i][j] = res[i-1][j] + grid[i][j];
            }
        }
        return res[grid.size()-1][grid[0].size()-1];
    }
};