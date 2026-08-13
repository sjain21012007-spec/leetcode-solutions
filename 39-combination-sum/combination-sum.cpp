class Solution {
public:
    void generate(int i , vector<vector<int>> & ans,vector<int>& candidates, int target,vector<int> curr,int sum)
    {
        if(sum==target)
        {
             ans.push_back(curr);
            return;
        }
        else if(i== candidates.size() || sum>target)
        {
            return ;
        }
        else{
            generate(i+1,ans,candidates,target,curr,sum);
            sum+=candidates[i];
            if(sum<=target)
            {
            curr.push_back(candidates[i]);
            generate(i,ans,candidates,target,curr,sum);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> curr;
       int sum =0;
       generate(0,ans,candidates,target,curr,sum);
       return ans;
    }
};