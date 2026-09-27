class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> dp(n,0);
        dp[0]=1;
        int lon =1;
        int ans =1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            int ways =0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]){  
                   if(left[j]>=maxi)
                   {
                    if(left[j]==maxi) ways+=dp[j];
                    else{
                        ways=dp[j];
                    }
                    maxi= left[j];
                   }
                }
            }
            left[i]+=maxi;
            dp[i]= max(ways,1);
            if(left[i]>=lon)
            {
               if(left[i]==lon) ans+=dp[i];
                    else{
                        ans=dp[i];
                    }
                    lon= left[i];
            }
        }
        return ans;
    }
};