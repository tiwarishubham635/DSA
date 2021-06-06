int countPrimes(int n) 
    {
        if(n==0)
            return 0;
        
        long long* sieve = new long long[n+1];
        for(long long i=0;i<=n;i++)
            sieve[i]=1;
        sieve[0] = 0, sieve[1] = 0;
        long long ans = 0;
        for(long long i=2;i<n;i++)
        {
            if(sieve[i])
            {
                ans++;
                for(long long j=i*i;j<=n;j+=i)
                    sieve[j] = 0;
            }
        }
        return ans;
    }
