class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> req(n,0);
        int sum =0;
        for(int i=0;i<gas.size();i++)
        {
            req[i]= gas[i]- cost[i];
            sum+=req[i];
        }
        if(sum<0) return -1;
        int currcost =0;
        int currin = 0;
        for(int i=0;i<gas.size();i++)
        {
            currcost+=req[i];
            if(currcost<0)
            {
                currcost =0;
                currin= i+1;
            }
        }
        return currin;
    }
};