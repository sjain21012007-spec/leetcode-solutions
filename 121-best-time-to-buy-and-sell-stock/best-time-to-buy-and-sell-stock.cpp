class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int prev =0;
        int curr = 0;
        for(int i=2;i<=n;i++)
        {
            buy = min(prices[i-1],buy);
            curr = max(prev,prices[i-1]-buy);
            prev = curr;
        }
        return curr;
    }
};