int numTrees(int n) 
    {
        long long dp[n + 1];
        for(int i=0;i<=n;i++)
            dp[i]=0;
    
        // Base case
        dp[0] = 1;
        dp[1] = 1;
    
        // fill the dp table in top-down approach.
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
    
                // i-j in right * j-1 in left
                dp[i] = (dp[i] + (dp[i - j] * dp[j - 1]))%1000000007;
            }
        }
    
        return dp[n];
    }
