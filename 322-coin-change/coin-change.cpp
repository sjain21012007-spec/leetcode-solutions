class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        a.push_back(0);
        sort(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int price=1;price<=amount;price++)
            {
                int ans = dp[i-1][price];
                if(price<a[i]) dp[i][price]=ans;
                else 
                {
                    if(price%a[i]==0)
                    {
                       if(ans==-1) dp[i][price]=price/a[i];
                       else dp[i][price]=min(ans,price/a[i]);
                    }
                    for(int factor=1;factor<=price/a[i];factor++)
                    {
                        if(dp[i-1][price-factor*a[i]]==-1) continue;
                        else
                        {
                           if (ans==-1) ans = dp[i-1][price - factor * a[i]] + factor;
                            else ans=min(ans, dp[i-1][price - factor * a[i]] + factor);
                        }
                    } 
                }
                dp[i][price] = ans; 
            }
        }
        return dp[n][amount];
    }      
};