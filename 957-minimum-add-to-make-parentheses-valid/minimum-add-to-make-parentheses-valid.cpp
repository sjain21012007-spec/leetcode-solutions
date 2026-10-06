class Solution {
public:
    int minAddToMakeValid(string s) {
         int nb =0;
         stack<int> st;
         for(int i=0;i<s.length();i++)
         {
            if(s[i]=='(') st.push(s[i]);
            else{
                if(st.size()==0) nb++;
                else{
                    st.pop();
                }
            }
         }
         return nb+st.size();
    }
};