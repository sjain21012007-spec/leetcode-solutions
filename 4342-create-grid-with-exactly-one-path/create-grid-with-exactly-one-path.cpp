class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s ="";
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        vector<string> grid(m,s);
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                grid[i][j]='#';
            }
        } 
        return grid;
    }
};