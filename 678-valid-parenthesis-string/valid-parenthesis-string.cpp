class Solution {
public:
    bool f(int o,int c ,int i,string& s,vector<vector<vector<int>>> & dp)
    {
        if(i==s.length())
        {
            if(o==c) return true;
            return false;
        }
        if(dp[o][c][i]!=-1) return dp[o][c][i];
        if(c>o) return false;
        bool ans = false;
        if(s[i]=='(') return dp[o][c][i] = ans || f(o+1,c,i+1,s,dp);
        if(s[i]==')') return dp[o][c][i] = ans || f(o,c+1,i+1,s,dp);
        else 
        {
            ans = ans || f(o+1,c,i+1,s,dp);
            ans = ans || f(o,c+1,i+1,s,dp);
            ans = ans || f(o,c,i+1,s,dp);
        }
        return dp[o][c][i] = ans;
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(100,vector<vector<int>>(100,vector<int>(100,-1)));
        return f(0,0,0,s,dp);
    }
};