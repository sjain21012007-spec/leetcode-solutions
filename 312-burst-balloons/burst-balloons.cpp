class Solution {
public:
    int f(int i ,int j ,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(i==j)
        {
            return nums[i-1]*nums[i]*nums[i+1];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = -1;
        for(int k=i;k<=j;k++)
        {
           maxi = max(maxi,nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+ f(k+1,j,nums,dp));
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size(),0));
        for(int i=1;i<=nums.size()-2;i++)
        {
           dp[i][i]= nums[i-1]*nums[i]*nums[i+1];
        }
        for(int i =nums.size()-2;i>0;i--)
        {
            for(int j=i;j<=nums.size()-2;j++)
            {
                 int maxi = -1;
                 for(int k=i;k<=j;k++)
                 {
                  maxi = max(maxi,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+ dp[k+1][j]);
                 }
                 dp[i][j] = maxi;
            }
        }
        return dp[1][nums.size()-2];
    }
};