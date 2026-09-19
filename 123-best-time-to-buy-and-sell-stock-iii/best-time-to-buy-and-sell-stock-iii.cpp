class Solution {
public:
    int f(int i , int buy,int sold,int& n ,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
       if(sold==2  || i==n) return 0;
       if(dp[i][buy][sold]!=-1) return dp[i][buy][sold];
       if(buy)
       {
           return dp[i][buy][sold] = max(-prices[i]+f(i+1,0,sold,n,prices,dp),f(i+1,1,sold,n,prices,dp));
       }  
       else{
           return dp[i][buy][sold]= max(prices[i]+f(i+1,1,sold+1,n,prices,dp),f(i+1,0,sold,n,prices,dp));
       }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy =1;
        int i =0;
        int sold = 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,-1)));
        return f(i,buy,sold,n,prices,dp);
    }
};