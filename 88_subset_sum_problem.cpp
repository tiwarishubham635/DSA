bool helper(int a[], int n, int sum)
    {
        /*if(n==0)
            return (sum<=0);
        if(sum==0)
            return true;
        if(a[n-1]>sum)
            return helper(a,n-1,sum);
        return helper(a,n-1,sum-a[n-1]) or helper(a,n-1,sum);*/
        
        int** dp = new int*[2];
        for(int i=0;i<2;i++)
        {
            dp[i]=new int[sum+1];
            for(int j=0;j<=sum;j++)
                dp[0][j]=0;
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(a[n-i]>j)
                    dp[i%2][j]=dp[(i-1)%2][j];
                else dp[i%2][j]=(dp[(i-1)%2][j-a[n-i]] or dp[(i-1)%2][j]);
            }
        }
        return dp[n%2][sum];
    }
    
    bool findPartition(int a[], int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            sum += a[i];
        if(sum%2)
            return false;
        return helper(a, n, sum/2);
    }
