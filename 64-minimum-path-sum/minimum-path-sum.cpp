class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m =a.size();
        int n =a[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(i==0 && j==0) continue;
               int up =INT_MAX;
               int left =INT_MAX;
               if(i>0) up = a[i-1][j];
               if(j>0) left = a[i][j-1];
               a[i][j]+=min(up,left);
            }
        }
        return a[m-1][n-1];
    }
};