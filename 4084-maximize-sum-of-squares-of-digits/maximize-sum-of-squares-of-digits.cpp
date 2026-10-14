class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
        string s ="";
        for(int i=0;i<num;i++)
        {
            if(sum==0) s+='0';
            else if(sum<9)
            {
                s+= sum+'0';
                sum=0;
            }
            else{
                s+='9';
                sum-=9;
            }
        }
        return s;
    }
};