class Solution {
public:
    int uniquePaths(int m, int n) {
          long long ans =1;
          int total = m+n-2;
          int row = m-1;
          int col = n-1;
          for(int i=m;i<=m+n-2;i++)
          {
            ans = ans*(i)/(i-m+1);
          }
          return ans;
    }
};