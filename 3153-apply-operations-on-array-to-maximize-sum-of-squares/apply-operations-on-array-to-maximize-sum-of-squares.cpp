class Solution {
public:
    int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
       int n= nums.size();
       vector<int> bitc(31,0);
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<31;j++)
           {
              if((nums[i]>>j)&1)
              {
                bitc[j]++;
              }
           }
       }
       int ans =0;
       for(int i=0;i<k;i++)
       {
           long long curr=0;
           for(int j=0;j<31;j++)
           {
             if(bitc[j]>0)
             {
                 curr |= (1 << j);
                 bitc[j]--;
             }
           }
           ans+=(curr*curr)%mod;
           ans=ans%mod;
       }
       return ans;
    }
};