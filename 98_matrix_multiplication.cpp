int mat_mult(int arr[], int s, int e)
    {
        if(s==e)
            return 0;
        
        int m = INT_MAX;
        for(int i=s;i<e;i++)
            m = min(m, mat_mult(arr, s, i)+mat_mult(arr, i+1, e)+arr[s-1]*arr[i]*arr[e]);
        
        return m;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        //return mat_mult(arr, 1, n-1);
        int** dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            dp[i][i] = 0;
        }
        
        for(int i=n-2;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
        }
        return dp[1][n-1];
    }
