class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        int n = a.size();
        int ans = n+1;
        int l =0;
        int sum= 0;
        vector<int> dp(n+1,n);
        for(int r =0 ;r<n;r++)
        {
           sum+=a[r];
           while(sum>target)
           {
              sum-=a[l];
              l++;
           }
           dp[r+1]= dp[r];
           if(sum==target)
           {
               ans = min(ans,r-l+1+dp[l]);
               dp[r+1]=min(dp[r],r-l+1); 
           }
        }
        return ans == n+1? -1 : ans;
    }
};