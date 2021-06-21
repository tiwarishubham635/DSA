int kInversePairs(int n, int k) 
    {
        int mod = 1000000007;
        int** dp = new int*[2];
        for(int i=0;i<2;i++)
        {
            dp[i] = new int[k+1];
            dp[i][0]=1;
        }
        for(int i=0;i<=k;i++)
            dp[0][i]=0;

        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++) 
            {
                dp[i%2][j] = (dp[(i - 1)%2][j] + dp[i%2][j - 1]) % mod;
                if (j >= i)
                    dp[i%2][j] = (mod + dp[i%2][j] - dp[(i - 1)%2][j - i]) % mod;
            }
        }
            
        return dp[n%2][k];
    }
