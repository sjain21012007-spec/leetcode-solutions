class Solution {
public:
    int f(vector<int>& nums,int target, int in,vector<vector<int>>& dp,int& sum)
    {
        if (target > sum || target < -sum) {
            return 0;
        }
        if(in==0)
        {
            if(nums[0]==target || nums[0]==-target)
            {
                if(nums[0]==0) return 2;
                return 1;
            }
            return 0;
        }
        if(dp[in][target+sum]!=-1) return dp[in][target+sum];
        int add = f(nums,target+nums[in],in-1,dp,sum);
        int sub = f(nums,target-nums[in],in-1,dp,sum);

        return dp[in][target+sum] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int in = nums.size()-1;
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];  
        if (target > sum || target < -sum) {
            return 0;
        } 
        vector<vector<int>> dp(in+1,vector<int> (2*sum+1,-1));
        int ans = f(nums,target,in,dp,sum);
        return ans;
    }
};