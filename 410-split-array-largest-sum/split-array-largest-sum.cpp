class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(),a.end());
        int high = accumulate(a.begin(),a.end(),0);
        while(low<=high)
        {
            int mid = (low+high)/2;
            int component =1;
            int current =0;
            for(int i=0;i<a.size();i++)
            {
               if(current+a[i]<=mid)
               {
                current +=a[i];
               }
               else{
                component++;
                current = a[i];
               }
            }

            if(component>k)
            {
             low = mid+1;   
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};