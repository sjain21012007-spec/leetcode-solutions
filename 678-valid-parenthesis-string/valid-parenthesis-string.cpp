class Solution {
public:
    bool f(int cnt,int i,string& s,vector<vector<int>> & dp)
    {
        if(i==s.length())
        {
            if(cnt==100) return true;
            return false;
        }
        if(dp[cnt][i]!=-1)return dp[cnt][i];
        if(cnt<100) return false;
        bool ans = false;
        if(s[i]=='(') return  dp[cnt][i]  =ans || f(cnt+1,i+1,s,dp);
        if(s[i]==')') return  dp[cnt][i] = ans || f(cnt-1,i+1,s,dp);
        else 
        {
            ans = ans || f(cnt+1,i+1,s,dp);
            ans = ans || f(cnt-1,i+1,s,dp);
            ans = ans || f(cnt,i+1,s,dp);
        }
        return  dp[cnt][i] =  ans;
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(201,vector<int>(100,-1));
        return f(100,0,s,dp);
    }
};