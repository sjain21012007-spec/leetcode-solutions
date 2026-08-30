class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        a.push_back(0);
        sort(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        for(int i =0;i<=amount;i++)
        {
            dp[0][i]= 1e9;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int price=1;price<=amount;price++)
            {
               int notake= dp[i-1][price];
               int take = INT_MAX;
               if(price>=a[i])  take = 1+dp[i][price-a[i]];
               dp[i][price] = min(notake,take);
            }
        }
        if(dp[n][amount]>=1e9) return -1;
        return dp[n][amount];
    }      
};