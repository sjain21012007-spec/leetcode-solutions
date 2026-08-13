class Solution {
public:
    void generate(int i, vector<vector<int>>& ans, vector<int>&candidates,int target,vector<int> curr)
   {
       if(target==0)
       {
        ans.push_back(curr);
        return;
       }
       for(int j =i;j<candidates.size();j++)
       {
        if(j>i && candidates[j]==candidates[j-1]) continue;
        if(candidates[j]>target) break;
        curr.push_back(candidates[j]); 
        generate(j+1,ans,candidates,target-candidates[j],curr);
        curr.pop_back();
       }
       
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        generate(0,ans,candidates,target,curr);
        return ans;
    }
};