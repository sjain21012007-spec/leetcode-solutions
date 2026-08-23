class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int na = nums[0];
        int a = nums[1];
        for(int i=2;i<nums.size();i++)
        {
           int curr = na+nums[i];
            na = max(a,na);
            a = curr;
        }
      return max(a,na); 
    } 
};