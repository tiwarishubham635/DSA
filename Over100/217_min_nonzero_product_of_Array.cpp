class Solution {
    int mod = 1e9+7;
public:
    
    long long power(long long a, long long b)
    {
        if(b==0)
            return 1;
        
        long long val = power(a, b/2);
        long long sq = (val*val)%mod;
        
        if(b&1)
            return (sq * (a%mod))%mod;
        
        return sq%mod;
    }
    
    
    int minNonZeroProduct(int p) {
        long long cnt = (1ll << p) - 1;
        return cnt % mod * power(cnt - 1, (cnt-1) / 2) % mod;
    }
};
