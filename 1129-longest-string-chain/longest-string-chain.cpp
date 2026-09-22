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
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size(); 
             }
        return a < b; 
          });
        vector<int>  dp(n+1,1);
        int maxa=1;
        for(int i =1;i<n;i++)
        {
            for(int prev =0;prev<i;prev++)
            {
               if(good(words[i],words[prev]))
               {
                dp[i]= max(dp[i],dp[prev]+1);
               }
            }
            maxa= max(dp[i],maxa);
        }
        return maxa;
    }
};