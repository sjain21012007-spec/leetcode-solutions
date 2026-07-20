class Solution {
public:
    string removeOuterParentheses(string s) {
        int k=0;
        string f ="";
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
            if(k>0)
                {
                f=f+s[i];
                }
            k++;
            }
            else 
            {
                k--;
                if(k>0)
                {
                f=f+s[i];
                }
            
            }
        }
        return f;
    }


};