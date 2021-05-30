long long maximumAmount(int arr[], int n) 
	{
	    /*if(n==0)
		return 0;
	    if(n==1)
		return (long long)arr[0];

	    long long last = arr[n-1] + min(maximumAmount(arr+1,n-2), maximumAmount(arr,n-2));
	    long long first = arr[0] + min(maximumAmount(arr+2,n-2), maximumAmount(arr+1,n-2));

	    return max(first, last);*/

	    int** dp = new int*[n+1];
	    for(int i=0;i<=n;i++)
	    {
		dp[i]= new int[n-i+1];
		dp[i][0] = 0;
		if(i!=n)
		    dp[i][1] = arr[i];
	    }

	    for(int i=n;i>=0;i--)
	    {
		for(int j=2;j<=(n-i);j++)
		{
		    dp[i][j] = max(arr[i+j-1]+min(dp[i+1][j-2], dp[i][j-2]), arr[i]+min(dp[i+2][j-2], dp[i+1][j-2]));
		}
	    }

	    return dp[0][n];
	}
