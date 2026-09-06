class Solution {
public:
    int f(int n ,int m ,string s , string k,vector<vector<int>>& dp)
    {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==k[m-1]) return dp[n][m] = 1 + f(n-1,m-1,s,k,dp);
        return dp[n][m] = max(f(n-1,m,s,k,dp),f(n,m-1,s,k,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        return n+m - 2*f(n,m,word1,word2,dp);
    }
};