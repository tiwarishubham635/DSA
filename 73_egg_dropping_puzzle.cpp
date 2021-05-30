int eggDrop(int n, int k) 
    {
        /*if(n==1)
            return k;
        if(k==1)
            return 1;
        if(k==0)
            return 0;
        int ans = INT_MAX;
        int r = INT_MIN;
        for(int i=1;i<=k;i++)
        {
            r = max(eggDrop(n,k-i), eggDrop(n-1,i-1));
            if(ans > r)
                ans = r;
        }
        return ans+1;*/
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] = new int[k+1];
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
            dp[i][1]=1;
        }
        
        for(int i=0;i<=k;i++)
        {
            dp[1][i] = i;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                int r = INT_MIN, ans = INT_MAX;
                for(int x=1;x<=j;x++)
                {
                    r = max(dp[i][j-x], dp[i-1][x-1]);
                    if(ans>r)
                        ans = r;
                }
                dp[i][j] = ans+1;
            }
        }
        return dp[n][k];
    }

