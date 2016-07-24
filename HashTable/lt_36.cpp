class Solution {
public:
	//28ms using hashtable
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

class Solution {
public:
//14ms,use bit manipulation instead of hashtable
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> matrix(9,0);
        if(board.size() == 0)
            return false;
        for(int r = 0;r < board.size();r++)
        {
            for(int c = 0;c<board[0].size();c++)
            {
                char tmp = board[r][c];
                if(tmp == '.')
                    continue;
                int digit = tmp-'.';
                int mask = 1 << digit;
                if(row[r] & mask || col[c] & mask || matrix[r/3*3+c/3] & mask)
                    return false;
                row[r] |= mask;
                col[c] |= mask;
                matrix[r/3*3+c/3] |= mask;
            }
        }
        return true;
    }
};
