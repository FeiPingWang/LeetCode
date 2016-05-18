class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() <= 0)
            return 0;
        vector<vector<int>> res(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        res[0][0] = 1;
        for(int i=0;i<obstacleGrid.size();i++)
        {
            for(int j=0;j<obstacleGrid[0].size();j++)
            {
                if(obstacleGrid[i][j] == 1)
                    res[i][j] = 0;
                else
                {
                    if(i > 0 && j > 0)
                        res[i][j] = res[i][j-1] + res[i-1][j];
                    else if(i > 0 && j == 0)
                        res[i][j] = res[i-1][j];
                    else if(i == 0 && j > 0)
                        res[i][j] = res[i][j-1];
                }
            }
        }
        return res[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};