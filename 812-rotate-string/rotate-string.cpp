class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        } 
        s = s+s;
        int ans=0;
        int curl=0;
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(j<goal.length() && s[i]==goal[j] )
            {
                curl++;
                j++;
            }
            else if(j<goal.length() && s[i]==goal[0])
            {
                curl =1;
                j=1;
            }
            else{
                ans = max(ans,curl);
                curl =0;
                j=0;
            }
        } 
        if(ans==goal.length()) return true;

        return false;
  }
};