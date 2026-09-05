class Solution {
public:
   
    int minInsertions(string s) {
        int n = s.size();
        string k = s;
        reverse(s.begin(),s.end());
        vector<int> curr(n+1,0), prev(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==k[j-1]) curr[j]= 1+ prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev= curr;
        }
        return n - prev[n];
    }
};