class Solution {
public:
    int f(int i, int buy , int& n , vector<int>& prices,vector<vector<int>> & dp)
    {
        if(i==n || i==n+1) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            return dp[i][buy] = max(-prices[i] + f(i+1,0,n,prices,dp),f(i+1,1,n,prices,dp));
        }
        else{
            return dp[i][buy]= max(prices[i] + f(i+2,1,n,prices,dp),f(i+1,0,n,prices,dp));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i =0;
        int buy =1;
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(i,buy,n,prices,dp);
    }
};