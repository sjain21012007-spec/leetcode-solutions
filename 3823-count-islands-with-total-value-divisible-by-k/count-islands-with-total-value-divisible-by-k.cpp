class Solution {
public:
    int m,n;
    long long f(vector<vector<int>>& grid , int i ,int j ,vector<vector<int>> & visited)
    {
        if(i<0 ||j<0 || i>=m || j>=n || grid[i][j]==0 || visited[i][j]==1) return 0;
        visited[i][j]=1;
        return (long long)grid[i][j] + f(grid,i+1,j,visited) + f(grid,i-1,j,visited)+f(grid,i,j+1,visited)+f(grid,i,j-1,visited);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        int ans =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 || visited[i][j]==1) continue;
                long long sum = f(grid,i,j,visited);
                if(sum%k==0) ans++;
            }
        }
        return ans;
    }
};