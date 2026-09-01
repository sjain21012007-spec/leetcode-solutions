class Solution {
public:
    int f(int n , int amount,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(n==0)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
            int nottake = f(n-1,amount,coins,dp);
            int take = 0;
            if(amount>=coins[n]) take = f(n,amount-coins[n],coins,dp);
            return  dp[n][amount] = nottake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size()-1;
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int ans = f(n,amount,coins,dp);
        return ans;
    }
};