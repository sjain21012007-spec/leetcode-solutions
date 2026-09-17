class Solution {
public:
    bool f(int i,int j , string& s , string& p,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)  return true;
        if(i>0 && j==0)  return false;
        if(i==0 && j>0)
        {
          for(int f=1;f<=j;f++)
          {
            if(p[f-1]!='*') return false;
          }
          return true;
        }
        if(j==0)
        {
           return false; 
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j-1]=='*')
        {
            if(f(i-1,j,s,p,dp)) return dp[i][j] = true;
            if(f(i,j-1,s,p,dp)) return dp[i][j] =true;
        }
        else if(p[j-1]=='?' || s[i-1]==p[j-1])
        {
            if(f(i-1,j-1,s,p,dp)) return dp[i][j] = true;
        } 
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(n,m,s,p,dp);
    }
};