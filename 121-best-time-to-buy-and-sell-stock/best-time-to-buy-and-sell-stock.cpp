class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1,0);
        int buy = prices[0];
        for(int i=2;i<=n;i++)
        {
            buy = min(prices[i-1],buy);
            dp[i] = max(dp[i-1],prices[i-1]-buy);
        }
        return dp[n];
    }
};