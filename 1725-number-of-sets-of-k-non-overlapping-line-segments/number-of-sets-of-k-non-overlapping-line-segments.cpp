class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int n , int k , int count,vector<vector<vector<int>>>& dp)
    {
        if(k==0)
        {
                return 1;
        }
        if(n==1)
        {
            if(k==1 && count==1)
            {
                return 1;
            }
            return 0 ; 
        }
        if(dp[n][k][count]!=-1) return dp[n][k][count];
        int ans =0 ;
        if(count==0)
        {
            ans+= f(n-1,k,0,dp)%MOD;

            ans += f(n-1,k,1,dp)%MOD;
        }
        if(count==1)
        {
            ans += f(n-1,k,1,dp)%MOD;
            ans+= f(n,k-1,0,dp)%MOD;
        }
        
        return dp[n][k][count] = ans%MOD;
    }
    int numberOfSets(int n, int k) {
          int count = 0 ;
          vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
          int ans = f(n,k,count,dp);
          return ans ;
    }
};