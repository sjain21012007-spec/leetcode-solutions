class Solution {
public:
    int f(int i ,int j , string& s , string& t,vector<vector<int>>& dp)
    {
        if(j==0) return 1;
        if(i==0) return 0;
        int ans = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1])
        {
           ans+= f(i-1,j-1,s,t,dp);
        }
        ans+=f(i-1,j,s,t,dp);

        return dp[i][j] = ans;
    }  
    int numDistinct(string s, string t) {
        int i = s.length();
        int j = t.length();
        vector<vector<int>> dp(i+1,vector<int> (j+1,-1));
        int ans = f(i,j,s,t,dp);
        return ans;
    }
};