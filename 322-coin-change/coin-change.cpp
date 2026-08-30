class Solution {
public:
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i =0;i<=amount;i++)
        {
           if(i%a[0]==0) prev[i]= i/a[0];
           else prev[i]=1e9;
        }
        curr =prev;
        for(int i=1;i<n;i++)
        {
            for(int price=0;price<=amount;price++)
            {
               int notake= prev[price];
               int take = INT_MAX;
               if(price>=a[i])  take = 1+curr[price-a[i]];
               curr[price] = min(notake,take);
            }
            prev =curr;
        }
        if(curr[amount]>=1e9) return -1;
        return curr[amount];
    }      
};