class Solution {
public:
    bool rowo(char c,int row,vector<vector<char>> & board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
            {
                return false;
            }
        }
         return true;
    }
    bool column(char c,int col ,vector<vector<char>> & board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)
            {
                return false;
            }
        }
         return true;
    }
    bool box(char c,int row,int col ,vector<vector<char>> & board)
    {
        int br = (row/3)*3;
        int cr = (col/3)*3;
        for(int i=br;i<br+3;i++)
        {
            for(int j=cr;j<cr+3;j++)
            {
                if(board[i][j]==c)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool safe(char c,int row,int col ,vector<vector<char>> & board)
    {
        if(!rowo(c,row,board))
        {
            return false;
        }
        if(!column(c,col,board))
        {
            return false;
        } 
        if(!box(c,row,col,board))
        {
            return false;
        }        
        return true;
    }
    bool solve(int row,int col , vector<vector<char>> & board)
    {
        if(col==9)
        {
            row++;
            col =0;
        }
        if(row ==9)
        {
            return true;
        }
        if(board[row][col]!='.')
        {
            return solve(row, col + 1, board);
        }
        for(char c = '1';c<='9';c++)
        {
          if(safe(c,row,col,board))
            {
                board[row][col]=c;
                if (solve(row, col + 1, board))
                {
                    return true;
                } 
                board[row][col]='.';
            }
        }
        return false; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        solve(row,col,board);
    }
};