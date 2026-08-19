class Solution {
public:
    bool safe(int r, int c,vector<string>& board, int n)
    {
            for(int j=c;j>=0;j--)
            {
                if(board[r][j]=='Q')
                {
                    return false;
                }
            }
            int r1 = r;
            int c1 =c;
             while(r>=0 && c>=0)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                r--; c--;
            }
            r =r1;
            c=c1;
             while(r<n && c<n)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                r++; c++;
            }
            r =r1;
            c=c1;
             while(r<n && c>=0)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                r++; c--;
            }
            r =r1;
            c=c1;
             while(r>=0 && c<n)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                r--; c++;
            }
      return true;
    }
    void solve(int col , vector<string>& board,vector<vector<string>>& ans, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            int c = col;
            int r=i;
            if(safe(r,c,board,n))
            {
                board[r][c]='Q';
                solve(c+1,board,ans,n);
                board[r][c]='.';
            }
        }

        
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n,'.');
       for(int i=0;i<n;i++)
       {
         board[i]= s;
       }
       for(int i=0;i<n;i++)
       {
         board[i][0]='Q';
         solve(1,board,ans,n);
         board[i][0]='.';
       }
       return ans;
    }
};