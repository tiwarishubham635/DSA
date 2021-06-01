int maxProfit(int k, int n, int arr[]) 
    {
        int** dp = new int*[k+1];
        for(int i=0;i<=k;i++)
        {
            dp[i] = new int[n];
            dp[i][0]=0;
            
            for(int j=0;j<n;j++)
                dp[0][j] = 0;
        }
        
        for(int i=1;i<=k;i++)
        {
            int prev=INT_MIN;
            for(int j=1;j<n;j++)
            {
                prev = max(prev, dp[i-1][j-1]-arr[j-1]);
                dp[i][j] = max(prev+arr[j], dp[i][j-1]);
            }
        }
        return dp[k][n-1];
    }
