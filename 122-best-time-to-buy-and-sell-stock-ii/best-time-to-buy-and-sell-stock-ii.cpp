class Solution {
public:
    int f(int i ,int buy, int& n, vector<int>& prices,vector<vector<int>> & dp )
    {
       if(i==n)
       {
           return 0;
       }
       if(dp[i][buy]!=-1) return dp[i][buy];
       if(buy)
       {
          return dp[i][buy] = max(-prices[i] + f(i+1,0,n,prices,dp), f(i+1,1,n,prices,dp));
       }
       else{
          return dp[i][buy] =max(prices[i]+ f(i+1,1,n,prices,dp), f(i+1,0,n,prices,dp));
       }
       return 1;
    }
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int buy = 1;
       int i = 0;
       if(n==1) return 0;
       vector<vector<int>> dp(n+1,vector<int> (2,-1));
       return  f(i,buy,n,prices,dp);
    }
};