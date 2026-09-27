class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        for(int i=1;i<n;i++)
        {
            int maxi =0;
            for(int j = 0 ;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    maxi= max(maxi,left[j]);
                }
            }
            left[i]+=maxi;
        }
        vector<int> right(n,1);
        for(int i=n-2;i>=0;i--)
        {
            int maxi =0;
            for(int j = n-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    maxi= max(maxi,right[j]);
                }
            }
            right[i]+=maxi;
        }
        int ans =0;
        for (int i = 0; i < n; i++) {
			if (left[i] != 1 && right[i] != 1)
				ans = max(left[i] + right[i] - 1, ans);
		}
		return n - ans;
    }
};