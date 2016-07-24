class Solution {
public:
    /* 就是求连通子图，1代表有边，0代表无边 */
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i=0;i < grid.size();i++)
        {
            for(int j=0;j < grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    num++;
                    DFS(grid,i,j);
                }
            }
        }
        return num;
    }
    
    void DFS(vector<vector<char>>& grid,int x,int y)
    {
        if(x >= grid.size() || x < 0 || y < 0 || y >= grid[x].size())            //判断边界
            return;
        if(grid[x][y] == '1')
        {
            grid[x][y] = '0';
            DFS(grid,x-1,y);
            DFS(grid,x+1,y);
            DFS(grid,x,y-1);
            DFS(grid,x,y+1);
        }
    }
};