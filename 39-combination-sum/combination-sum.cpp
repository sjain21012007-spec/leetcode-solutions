class Solution {
public:
    void generate(int i , vector<vector<int>> & ans,vector<int>& candidates, int target,vector<int> curr,int sum,map<vector<int>,int>& m)
    {
        if(sum==target)
        {
            if(m[curr]==0)
            {
                ans.push_back(curr);
                m[curr]++;
            }
            return;
        }
        else if(i== candidates.size() || sum>target)
        {
            return ;
        }
        else{
            generate(i+1,ans,candidates,target,curr,sum,m);
            sum+=candidates[i];
            curr.push_back(candidates[i]);
            generate(i,ans,candidates,target,curr,sum,m);
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> curr;
       map<vector<int>,int> m;
       int sum =0;
       generate(0,ans,candidates,target,curr,sum,m);
       return ans;
    }
};