class Solution {
public:
    bool f(int target, vector<int>& nums ,int i,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool nt = f(target,nums,i-1,dp);
        bool take =false;
        if(nums[i]<=target) take = f(target-nums[i],nums,i-1,dp);

        return dp[i][target] = nt | take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i=0;i<n;i++)
        {
         target+=nums[i];  
        }
        if(target%2) return false;
        target = target/2;
        int index = n-1;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        bool ans = f(target,nums,index,dp);
        return ans;
    }
};