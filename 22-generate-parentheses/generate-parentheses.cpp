class Solution {
public:
void f(int o ,int c ,string s , vector<string>& ans)
{
    if(o==c && o==0)
    {
        ans.push_back(s);
        return ;
    }
    if(o>0) f(o-1,c,s+'(', ans);
    if(o<c) f(o,c-1,s+')',ans);
    return ;
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        string curr = "";
        f(n,n,curr,ans);
        return ans;
    }
};