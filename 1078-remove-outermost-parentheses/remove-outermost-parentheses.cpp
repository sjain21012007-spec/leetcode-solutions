class Solution {
public:
    string removeOuterParentheses(string s) {
        int curr=0;
        string a  ="";
        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='(')
           {
               if(curr!=0) a+=s[i]; 
               curr++;
           }
           else{
              if(curr!=1) a+=s[i];
              curr--;
           }
        }
        return a;
    }
};