class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) return false;
        int low =0;
        int high = matrix.size()-1;
        while(high>=low)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0]>target)
            {
                high = mid-1;
            }
            else if(matrix[mid][0]<target)
            {
                low =mid+1;
            }
            else{
                return true;
            }
        }
        int row = high;
        if (row < 0) return false;
        low =0;
        high=matrix[0].size()-1;
        while(high>=low)
        {
            int mid = (low+high)/2;
            if(matrix[row][mid]>target)
            {
                high = mid-1;
            }
            else if(matrix[row][mid]<target)
            {
                low =mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};