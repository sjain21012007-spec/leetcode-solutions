class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power (long long b , long long e)
    {
        b = b%MOD;
        if(e==1) return b;
        if(e==0) return 1;
        if(e%2) return b*power((b*b)%MOD, e/2)%MOD;
        else  return power(b*b%MOD,e/2)%MOD;
    }
    int countGoodNumbers(long long n) {
        
        long long e = (n+1)/2;
        long long o = n/2;

        long long ec = power(5,e)%MOD;
        long long oc = power(4,o)%MOD;

        return (ec*oc)%MOD;
    }
};