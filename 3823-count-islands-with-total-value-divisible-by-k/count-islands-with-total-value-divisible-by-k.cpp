class Solution {
public:
    int m,n;
    long long f(vector<vector<int>>& grid , int i ,int j)
    {
        if(i<0 ||j<0 || i>=m || j>=n || grid[i][j]==0) return 0;
        int val = grid[i][j];
        grid[i][j]=0;
        return (long long)val + f(grid,i+1,j) + f(grid,i-1,j)+f(grid,i,j+1)+f(grid,i,j-1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                long long sum = f(grid,i,j);
                if(sum%k==0) ans++;
            }
        }
        return ans;
    }
};