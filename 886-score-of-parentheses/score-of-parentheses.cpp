class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> dp(51,0);
        stack<char> st;
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else{
                int level = st.size();
                st.pop();
                if(dp[level+1]==0) dp[level]++;
                else{
                    dp[level]+=2*dp[level+1];
                    dp[level+1]=0;
                }
            }
        }
        return dp[1];
    }
};