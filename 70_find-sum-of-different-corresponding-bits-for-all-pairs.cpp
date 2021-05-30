int countBits(int n, long long int a[])
{
    unsigned int ans=0, mod = 1000000007;
    for(int i=0;i<32;i++)
    {
        int ct=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]&(1<<i))
                ct++;
        }
        ans += ct*(n-ct)*2;
        ans %= mod;
    }
    return ans%mod;
}
