class Solution {
public:
    bool p(int i ,int j ,string& a)
    {
        for(int k =0;k<=(j-i)/2;k++)
        {
            if(a[i+k]!=a[j-k])
            {
                return 0;
            }
        }
        return 1;
    }
    int f(int i ,int j , string& s,vector<vector<int>> & dp)
    {
        if(i==j) return 0;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
         if(p(i,j,s)) return dp[i][j] = 0;
        int mini =  1e9;
        for(int k=i+1;k<=j;k++)
        {
            if(p(i,k-1,s))
            {
                mini = min(mini , 1+ f(k,j,s,dp));
            }
        }
        return dp[i][j] = mini ;
    }
    int minCut(string s) {
        int i =0;
        int  j = s.length()-1;
        vector<vector<int>> dp(j+1,vector<int> (j+1,-1));
        if(p(i,j,s)) return 0;
        return f(i,j,s,dp);
    }
};