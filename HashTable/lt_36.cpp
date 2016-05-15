class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return false;
        vector<char> mp;
        vector<vector<char>> vu(9,mp);
        for(int i=0;i<board.size();i++) //行
        {
            mp.clear();
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                    continue;
                if(find(mp.begin(),mp.end(),board[i][j]) != mp.end() || board[i][j] < '0' || board[i][j] > '9')
                    return false;
                mp.push_back(board[i][j]);
            }
        }
        for(int i=0;i<board[0].size();i++)//列
        {
            mp.clear();
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i] == '.')
                    continue;
                if(find(mp.begin(),mp.end(),board[j][i]) != mp.end() || board[j][i] < '0' || board[i][j] > '9')
                    return false;
                mp.push_back(board[j][i]);
            }
        }
        for(int i=0;i<board.size();i++) //九宫格
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                    continue;
                int n = (i / 3)*3 + j / 3;
                if(find(vu[n].begin(),vu[n].end(),board[i][j]) != vu[n].end()|| board[i][j] < '0' || board[i][j] > '9')
                    return false;
                vu[n].push_back(board[i][j]);
            }
        }
        return true;
    }
};