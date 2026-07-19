class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
          int  n = mat.size();
          int  m = mat[0].size();
          int low =0;
          int high = m-1; 

          while(high>=low)
          {
            int mid = (high+low)/2;
             
            int maxv = INT_MIN;
            int index =0;
            for(int i=0;i<n;i++)
            {
                if(mat[i][mid]>maxv)
                {
                    maxv=mat[i][mid];
                    index=i;
                }
            }
               
              int left = mid - 1 >= 0 ? mat[index][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? mat[index][mid + 1] : INT_MIN;
            
            if(mat[index][mid]>left && mat[index][mid]>right)
            {
                return {index,mid};
            }
            else if (left > mat[index][mid]) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
              }
          }
          return{-1,-1};
    }
};