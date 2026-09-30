class Solution {
public:
    int f(int i , int j ,int l , vector<int>& cut,vector<vector<int>>& dp)
    {
        if(i==j) return 0 ; 
        if(i>j) return 0;
        int mini = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k= i;k<j;k++)
        {
          mini = min(mini, l + f(i,k,l-cut[j]+cut[k],cut,dp)+f(k+1,j,cut[j]-cut[k],cut,dp));
        }
        return dp[i][j] = mini;
    }
    int minCost(int l, vector<int>& cuts) {
        int n = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(l);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        int i =0;int j = n;
        return f(i,j,l,cuts,dp);
    }
};