long long int count( int S[], int m, int n)
    {
        /*if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(m<=0&&n>=1)
            return 0;
        return count(S, m-1, n)+count(S,m,n-S[m-1]);
        long long** dp = new long long*[n+1];
        for(int i=0;i<=n;i++) 
        {
            dp[i] = new long long[m+1];
            for(int j=0;j<=m;j++)
                dp[0][j]=1;
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i>=S[j-1])
                    dp[i][j] = dp[i][j-1]+dp[i-S[j-1]][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];*/
        
        long long* dp = new long long[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=0;
        dp[0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=S[i];j<=n;j++)
                dp[j] += dp[j-S[i]];
        }
        return dp[n];
    }
