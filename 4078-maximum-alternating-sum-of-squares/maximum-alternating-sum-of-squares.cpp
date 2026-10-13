class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         int n = nums.size();
         for(int i=0;i<n;i++)
         {
            nums[i]=abs(nums[i]);
         }
         sort(nums.begin(),nums.end());
         long long ans = 0;
         for(int i=0;i<n/2;i++)
         {
            ans+= (long long)nums[n-1-i]*nums[n-1-i];
            ans-= (long long)nums[i]*nums[i];
         }
         if(n%2)
         {
            ans+=(long long)nums[n/2]*nums[n/2];
         }
         return ans;
    }
};