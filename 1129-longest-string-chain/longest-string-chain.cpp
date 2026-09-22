class Solution {
public:
    bool good(string& a,string& b)
    {
        if(a.length()!=1+b.length()) return false;
        int j =0;
        int cd =0;
        for(int i=0;i<a.length();i++)
        {
           if(a[i]!=b[j])
           {
               cd++;
           }
           else{
              j++;
           }
        }
        if(cd==1) return true;
        else return false;
    }
    int f(int i,int prev,int n,vector<string>& words,vector<vector<int>> & dp)
    {
        if(i==n)
        {
             if(prev!=0 && good(words[i-1],words[prev-1]))
             {
                return 2;
             } 
             return 1;
        }  
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(prev==0)
        {
            return dp[i][prev] =max(f(i+1,i,n,words,dp),f(i+1,0,n,words,dp));
        }
        else{
            if(good(words[i-1],words[prev-1]))
            {
             return dp[i][prev] =max(f(i+1,prev,n,words,dp),1+ f(i+1,i,n,words,dp));
            }
            else{
                return dp[i][prev] = f(i+1,prev,n,words,dp);
            }
        }
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size(); 
             }
        return a < b; 
          });
        int prev =0;
        int i=1;
        vector<vector<int>> dp(n+1,vector<int> (n,-1));
        return f(i,prev,n,words,dp);
    }
};