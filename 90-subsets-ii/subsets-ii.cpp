
class Solution {
public:
    void generate(int in , vector<int> curr, vector<vector<int>>& ans, vector<int>& nums)
    {
       if(in == nums.size())
       {
        ans.push_back(curr);
        return;
       }
        for(int j =in;j<nums.size();j++)
       {
        if(j>in && nums[j]==nums[j-1]) continue;
        curr.push_back(nums[j]); 
        if(j!=nums.size()-1)  ans.push_back(curr);
        generate(j+1,curr,ans,nums);
        curr.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     vector<vector<int>> ans;
     vector<int> curr;
     int i =0;
     generate(i,curr,ans,nums);
     ans.push_back({});
     return ans ;
    }
};