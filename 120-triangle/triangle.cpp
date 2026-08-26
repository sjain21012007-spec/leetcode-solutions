class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans =INT_MAX;
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int sam = INT_MAX;
                int pre = INT_MAX;
                if(j>0) pre = triangle[i-1][j-1];
                if(j<i) sam = triangle[i-1][j];
                triangle[i][j] += min(pre,sam);
                if(i==n-1)
                {
                    ans = min(ans,triangle[i][j]);
                }
            }
        }

        return ans;
    }
};