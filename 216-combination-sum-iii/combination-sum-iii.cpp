class Solution {
public:
    void generate(int i , vector<vector<int>>& ans, vector<int> curr,int k, int n)
    {
        if(i==10 || curr.size()==k)
        {
            if(n==0 && curr.size()==k)
            {
                ans.push_back(curr);
            }
            return ;
        }
         generate(i+1,ans,curr,k,n);
         if((n-i)>=0)
         {
         curr.push_back(i);
         generate(i+1,ans,curr,k,n-i);
         }
         return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int i = 1;
        vector<int> curr;
        generate(i,ans,curr,k,n);
        return ans;
    }
};