class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int na = nums[1];
        int a = nums[2];
        for(int i=3;i<nums.size();i++)
        {
           int curr = na+nums[i];
            na = max(a,na);
            a = curr;
        }
        int ans  = max(a,na);
        na = nums[0];
        a = nums[1];
        for(int i=2;i<nums.size()-1;i++)
        {
           int curr = na+nums[i];
            na = max(a,na);
            a = curr;
        }
        ans = max(ans,max(a,na));
        return ans;
    }
};