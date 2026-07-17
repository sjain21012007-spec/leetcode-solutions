class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int high = matrix[0].size()-1;
          for(int i=0;i<matrix.size();i++)
          {
            int low =0;
            while(low<=high)
            {
            int mid = (low+high)/2;
            if(matrix[i][mid]>target)
            {
                high = mid-1;
            }
            else if(matrix[i][mid]<target)
            {
                low =mid+1;
            }
            else{
                return true;
            }
            if(high<0)
            {
                return false;
            }
            }
          }
          return false;
    }
};