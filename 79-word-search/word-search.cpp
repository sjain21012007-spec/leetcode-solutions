class Solution {
public:
    bool generate(int r, int c,vector<vector<bool>>& v,int in , int  n, int m ,string& word,vector<vector<char>>& board)
    {
        if(in == word.length())
        {
            return true;
        }
        else if(r<0 || c<0 || r>n-1 || c>m-1 || v[r][c] == true)
        {
            return false;
        }
        bool ans = false;
        if(in==0)
        {
            if(c==m-1) ans = ans|| generate(r+1,0,v,in,n,m,word,board);
            else    ans = ans|| generate(r,c+1,v,in,n,m,word,board);
        }
        if(board[r][c]==word[in])
        {
            v[r][c]= true;
           if(generate(r-1,c,v,in+1,n,m,word,board) || generate(r,c-1,v,in+1,n,m,word,board) || generate(r+1,c,v,in+1,n,m,word,board) || generate(r,c+1,v,in+1,n,m,word,board))
           {
            ans = true;
           }
            v[r][c]= false;;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> v(n,vector<bool>(m,false));
        int r=0;
        int c=0;
        int in =0;
        bool ans = generate(r,c,v,in,n,m,word,board);
        return ans;
    }
};