int p = 1e9+7;
    long long power(long long x, long long y)
    {
        if(y==0)
            return 1;
        
        x %= p;
        if(x==0)
            return 0;
        
        long long ans = (power(x, y/2)%p);
        if(y&1)
            return (x*ans*ans)%p;
        return (ans*ans)%p;
    }
    int countGoodNumbers(long long n) 
    {
        if(n==1)
            return 5;
        long long ans = power(5, (n-(n/2)))%p;
        //cout<<ans<<endl;
        ans *= power(4, n/2)%p;
        return ans%p;
    }
