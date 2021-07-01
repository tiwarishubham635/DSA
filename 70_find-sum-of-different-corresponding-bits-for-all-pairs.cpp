void x(long long n, long long ar[])
    {
        long long t=0;
        while(n>0)
        {
            if(n%2)
                ar[t]++;
            ar[t]%=1000000007;
            t++;
            n/=2;
        }
    }
    int countBits(int n, long long int arr[])
    {
        /*int ans = 0;
        long long mod= 1000000007; 
        for (int i = 0; i < 32; i++) 
        {
            long long count = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i)))
                    count++;
    
            ans = (ans + count * (n - count) * 2)%mod;
        }*/

        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val = arr[i]^arr[j];
                while(val)
                    val = val&(val-1), ans = (ans + 1)%mod;
            }
        }*/
        
        long long i,ar[32],t=0;
        for(i=0;i<32;i++)
            ar[i]=0;
        for(i=0;i<n;i++)
            x(arr[i],ar);
        for(i=0;i<32;i++)
            t=(t+(2*ar[i]*(n-ar[i]))%1000000007)%1000000007;
        return t;
    }
