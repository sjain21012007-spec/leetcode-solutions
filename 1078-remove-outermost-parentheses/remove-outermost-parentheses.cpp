class Solution {
public:
    string removeOuterParentheses(string s) {
        int k=0;
        string f ="";
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(k==0)
            {
                k++;
                continue;
            }
            else if(s[i]=='(')
            {
                k++;
            }
            else if(s[i]==')')
            {
                k--;
            }
            
            if(k>0)
            {
                f=f+s[i];
            }
        }
        return f;
    }


};