class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
           int n = nums1.size();
           int maxdiff = -1e9;
           long long k = (long long)k1 + k2;
           vector<long long> count(100001, 0); 
           for(int i=0;i<n;i++)
           {
               int diff = abs(nums1[i]-nums2[i]);
               count[diff]++;
               maxdiff= max(diff,maxdiff);
           }
           for(int i =maxdiff;i>0;i--)
           {
              if(count[i]==0) continue;
              int take = min(k,count[i]);
              count[i] -= take;
              count[i - 1] += take;
              k -= take;
              if(k==0) break;
           }
           long long ans =0;
           for(int i=1;i<=maxdiff;i++)
           {
               ans += (long long)i*i*count[i];
           }
           return ans;
    }
};