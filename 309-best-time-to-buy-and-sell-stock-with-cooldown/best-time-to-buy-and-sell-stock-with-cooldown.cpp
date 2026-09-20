class Solution {
public:
    int f(int i, int buy,int cooldown , int& n , vector<int>& prices,vector<vector<vector<int>>> & dp)
    {
        if(i==n) return 0;
        if(dp[i][buy][cooldown]!=-1) return dp[i][buy][cooldown]; 
        if(cooldown) return f(i+1,1,0,n,prices,dp);
        if(buy)
        {
            return dp[i][buy][cooldown] = max(-prices[i] + f(i+1,0,0,n,prices,dp),f(i+1,1,0,n,prices,dp));
        }
        else{
            return dp[i][buy][cooldown] = max(prices[i] + f(i+1,1,1,n,prices,dp),f(i+1,0,0,n,prices,dp));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i =0;
        int buy =1;
        int cooldown = 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (2,-1)));
        return f(i,buy,cooldown,n,prices,dp);
    }
};