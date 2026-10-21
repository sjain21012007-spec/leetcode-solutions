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
        sort(s.begin(),s.end()-1);
        sort(k.begin()+1,k.end());
        if(a==s || a==k) 
        {
            return 1;
        }
        sort(s.begin()+1,s.end());
        sort(k.begin(),k.end()-1);
        if(a==s || a==k) 
        {
            return 2;
        }
        return 3;
    }
};