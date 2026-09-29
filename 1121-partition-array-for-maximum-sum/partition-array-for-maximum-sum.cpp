class Solution {
public:
    int f(int i,int n ,int s ,vector<int>& arr,vector<int> & dp)
    { 
        if(i==n) return 0;
        if(i>n) return 0;
        int maxi =-1;
        int maxv =-1;
        int len =0;
        if(dp[i]!=-1) return dp[i];
        for(int k=i;k<min(i+s,n);k++)
        {
            len++;
            maxv = max(maxv,arr[k]);
            maxi = max(maxi, maxv*len+ f(k+1,n,s,arr,dp));
        }
        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int s) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i =n-1;i>=0;i--)
        {
            int maxi =-1;
            int maxv =-1;
            int len =0;
            for(int k=i;k<min(i+s,n);k++)
             {
                 len++;
                  maxv = max(maxv,arr[k]);
                  maxi = max(maxi, maxv*len+ dp[k+1]);
             }
              dp[i] = maxi;
        }
        return dp[0];
    }
};