class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int buy = 1;
       int i = 0;
       if(n==1) return 0;
       vector<int> curr(2,0), prev(2,0);
       for(int i=n-1;i>=0;i--)
       {
        for(int buy = 0 ;buy<2;buy++)
         {
             if(buy)
             {
                curr[buy] = max(-prices[i] + prev[0], prev[1]);
             }
             else{
                curr[buy] =max(prices[i]+ prev[1], prev[0]);
             }
         }
         prev = curr;
       }
       return  prev[1];
    }
};