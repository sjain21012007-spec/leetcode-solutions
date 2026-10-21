class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string a  = s;
        string k =s;
        sort(a.begin(),a.end());
        if(a==s) 
        {
            return 0;
        }
        if(a[0]==s[n-1] && a[n-1]==s[0])
        {
            if(n==2) return -1;
        }
        else if(a[0]==s[0] ||a[n-1]==s[n-1])
        {
            return 1;
        }
         for (int i = 1; i + 1 < n; ++i) {
            if (s[i] == a[0] || s[i] == a[n-1]) {
                return 2;
            }
        }
        return 3;
    }
};