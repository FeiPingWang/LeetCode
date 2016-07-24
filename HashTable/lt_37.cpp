class Solution {
public:
	int row[9];
    int col[9];
    int matrix[9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r< board.size();r++)
        {
            for(int c = 0;c<board[0].size();c++)
            {
                char tmp = board[r][c];
                if(tmp == '.')
					continue;
                int digit = tmp-'0';
                int mask = 1 << digit;
                row[r] |= mask;
                col[c] |= mask;
                matrix[r/3*3+c/3] |= mask;
            }
		}
		findSolve(board,0,0);
    }
	bool findSolve(vector<vector<char>>& board,int Row,int Col)
	{
	    bool res;
		if(Row == 9)
			return true;
		char tmp = board[Row][Col];
		if(tmp != '.')
		{
		    if(Col == 8)
		        return findSolve(board,Row+1,0);
		    else
		        return findSolve(board,Row,Col+1);
		}
		else
		{
    		for(int bit = 1;bit < 10;bit++)
    		{
    			int mask  = 1 << bit;
    			if(!(row[Row] & mask || col[Col] & mask || matrix[Row/3*3+Col/3] & mask))
    			{
    			    int tmprow = row[Row];
    			    int tmpcol = col[Col];
    			    int tmpmatrix = matrix[Row/3*3+Col/3];
    			    
    				row[Row] |= mask;
    				col[Col] |= mask;
    				matrix[Row/3*3+Col/3] |= mask;
    				board[Row][Col] = bit +'0';
    				
    				if(Col == 8)
    					res = findSolve(board,Row+1,0);	//backtracking
    				else
    					res = findSolve(board,Row,Col+1);
    				if(res == true)
    				    return true;

    				row[Row] = tmprow;
    				col[Col] = tmpcol;
    				matrix[Row/3*3+Col/3] = tmpmatrix;
    				board[Row][Col] = '.';
    			}
    		}
		}
		return false;
	}
};
