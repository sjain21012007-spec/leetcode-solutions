class Solution {
public:
    int f(vector<int>& nums,int target, int in)
    {
        if(in==0)
        {
            if(nums[0]==target || nums[0]==-target)
            {
                if(nums[0]==0) return 2;
                return 1;
            }
            return 0;
        }

        int add = f(nums,target+nums[in],in-1);
        int sum = f(nums,target-nums[in],in-1);

        return add + sum;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int in = nums.size()-1;
        int ans = f(nums,target,in);
        return ans;
    }
};