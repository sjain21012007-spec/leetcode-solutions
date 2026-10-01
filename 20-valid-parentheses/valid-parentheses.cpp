class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(st.empty()) return 0;
            else if(s[i]==')')
            {
               if(st.top()!='(') return 0;
               else{
                  st.pop();
               }
            }
             else if(s[i]==']')
            {
               if(st.top()!='[') return 0;
               else{
                  st.pop();
               }
            } else if(s[i]=='}')
            {
               if(st.top()!='{') return 0;
               else{
                  st.pop();
               }
            }
        }
        if(st.empty()!=true) return 0;
        return 1;
    }
};