class Solution {
public:
    int mod = 1e9+7;
    int m ,n;
    int f(int  i ,int j ,vector<vector<int>>&grid ,vector<vector<vector<int>>>&dp ,int flag)
    {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][flag]!=-1) return dp[i][j][flag];
        int ans = 0;
        if(grid[i][j]==1)
        {
            if(flag==1) return dp[i][j][flag] = f(i,j+1,grid,dp,0)%mod;
            else return dp[i][j][flag] = f(i+1,j,grid,dp,1)%mod;
        }
        else{
            ans=(ans+f(i+1,j,grid,dp,1))%mod;
            ans=(ans+f(i,j+1,grid,dp,0))%mod;
        }
        return dp[i][j][flag] = ans%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(2,-1)));
        int ans = f(0,1,grid,dp,0)%mod;
        ans=(ans+f(1,0,grid,dp,1))%mod;
         return ans;
    }
};