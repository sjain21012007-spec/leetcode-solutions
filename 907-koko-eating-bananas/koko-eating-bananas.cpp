class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int hi =0;
        for(int i=0;i<n;i++)
        {
            hi = max(hi,piles[i]);
        }
        int low =0;
        int high = hi;
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            int ho=0;
            if(mid!=0)
            { 
            for(int i=0;i<n;i++)
            {
             ho += (piles[i]-1)/mid+1;
            }
            }
            else{
                ho = INT_MAX;
            }   
            if(ho>h)
            {
                low= mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return low;
    }

};