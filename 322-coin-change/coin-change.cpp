class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i =0;i<=amount;i++)
        {
           if(i%a[0]==0) dp[0][i]= i/a[0];
           else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int price=0;price<=amount;price++)
            {
               int notake= dp[i-1][price];
               int take = INT_MAX;
               if(price>=a[i])  take = 1+dp[i][price-a[i]];
               dp[i][price] = min(notake,take);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }      
};