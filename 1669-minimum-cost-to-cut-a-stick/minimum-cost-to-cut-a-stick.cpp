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
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        int i =1;int j = n;
        return f(i,j,cuts,dp);
    }
};