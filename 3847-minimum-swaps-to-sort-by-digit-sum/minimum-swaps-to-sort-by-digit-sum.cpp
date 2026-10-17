class Solution {
public:
    int digits(int n)
    {
        int sum =0;
        while(n>0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        map<pair<int,int>,int> m;
        vector<pair<int,int>> a;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            a.push_back({digits(nums[i]),nums[i]});
            m[a[i]]=i;
        }
        int swaps =0;
        vector<pair<int,int>> b = a;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
               int ind  = m[a[i]];
               swap(b[i],b[ind]);
               m[b[i]]=i;
               m[b[ind]] = ind; 
               swaps++;
            }
        } 
        return swaps;
    }
};