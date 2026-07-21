class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int end = strs[0].length();
        for(int i=1;i<n;i++)
        {
           int start =0;
           for(int j=0;j<strs[i].length();j++)
           {
             if(j<strs[i-1].length() && strs[i-1][j]==strs[i][j])
             {
                start++;
             }
             else{
                end = min(end,start);
                break;
             }
           }
           end = min(end,start);
        }
        return strs[0].substr(0,end);
    }
};