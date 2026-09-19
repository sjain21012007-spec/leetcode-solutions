class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        int buy =1;
        int i =0;
        int sold = 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                for(int sold =k-1;sold>=0;sold--)
                {
                    if(buy)
                    {
                       dp[i][buy][sold] = max(-prices[i]+dp[i+1][0][sold],dp[i+1][1][sold]);
                    }
                    else{
                       dp[i][buy][sold]= max(prices[i]+dp[i+1][1][sold+1],dp[i+1][0][sold]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};