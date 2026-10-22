class Solution {
public:
    int minOperations(vector<int>& a) {
         int n = a.size();
         if(n==1) return 0;
         bool is_sorted = true;
         for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                is_sorted = false;
                break;
            }
          }
        if (is_sorted) return 0;
         for(int i=0;i<n;i++)
         {
           if(a[i]==0)
           {
                if((i==n-1 && a[0]==n-1) || (i<n-1 && a[i+1]==n-1))
                {
                    vector<int> temp = a;
                    reverse(temp.begin()+i+1,temp.end());
                    reverse(temp.begin(),temp.begin()+i+1);
                    for(int j=0;j<n;j++)
                    {
                        if(temp[j]!=j) return -1;
                    }
                    return min(i + 2, n - i );
                }
                else if((i==n-1 && a[0]==1) || (i<n-1 && a[i+1]==1))
                {
                    vector<int> temp = a;
                    rotate(temp.begin(),temp.begin()+i,temp.end());
                    for(int j=0;j<n;j++)
                    {
                        if(temp[j]!=j) return -1;
                    }
                   return min(i, n - i+2);
                }
                return -1;
           }
         }
         return -1;
    }
};