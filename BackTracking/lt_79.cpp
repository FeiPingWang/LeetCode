class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;
        if(board.size() == 0)
            return false;
        vector<string> res;
        for(int i = 0; i < board.size();i++)
        {
            for(int j = 0; j < board[0].size();j++)
                if(FindDfs(board,word,"",0,i,j))
                    return true;
        }
        return false;
    }
    /*问题是怎么得到一个值就返回*/
   bool FindDfs(vector<vector<char>>& board,string word,string tmp,int num,int r,int c)
    {
        if(board[r][c] == word[num])
        {
            tmp += board[r][c];
            if(tmp == word)
                return true;
            board[r][c] = '#';                 //走过的要标记
            if(c < board[0].size()-1 && FindDfs(board,word,tmp,num+1,r,c+1))
                return true;
            if(c > 0 && FindDfs(board,word,tmp,num+1,r,c-1))
                 return true;
            if(r < board.size()-1 && FindDfs(board,word,tmp,num+1,r+1,c))
                return true;
            if(r > 0 && FindDfs(board,word,tmp,num+1,r-1,c))
                return true;
            board[r][c] = word[num];    //还原解空间
        }
        return false;
    }
};