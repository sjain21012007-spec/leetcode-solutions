class Solution {
public:
    int f(int i , int j, vector<int>& cut,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        int mini = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k= i;k<=j;k++)
        {
          mini = min(mini, cut[j+1] - cut[i-1] + f(i,k-1,cut,dp)+f(k+1,j,cut,dp));
        }
        return dp[i][j] = mini;
    }
    int minCost(int l, vector<int>& cuts) {
        int n = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(l);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for(int i =n;i>=1;i--)
        {
            for(int j = i;j<=n;j++)
            {
                int mini = 1e9;
               for(int k=i;k<=j;k++)
                {
                 mini = min(mini, cuts[j+1] - cuts[i-1] + dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n];
    }
};