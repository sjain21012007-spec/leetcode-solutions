class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int maxi = 1;
        int maxindex = 0;
        vector<int> hash(n,0);
        for(int i=1;i<n;i++)
        {
            hash[i] = i;
            for(int prev =0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0)
                {
                    if(dp[prev]+1>dp[i])
                    {
                        hash[i]=prev;
                        dp[i] = dp[prev]+1;
                    }
                }
            }
            if(dp[i]>maxi)
                {
                    maxi = dp[i];
                    maxindex = i;
                }
        }
        vector<int> ans;
        ans.push_back(nums[maxindex]);
        while(hash[maxindex]!=maxindex)
        {
            maxindex = hash[maxindex];
            ans.push_back(nums[maxindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};