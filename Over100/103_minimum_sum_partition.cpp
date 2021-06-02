int mindiff(int arr[], int n, int sum_cal, int sum)
	{
	    /*if(n==0)
	    {
	        int set1_sum = sum_cal;
	        int set2_sum = sum - sum_cal;
	        return abs(set1_sum - set2_sum);
	    }

	    return min(mindiff(arr, n-1, sum_cal+arr[n-1], sum), mindiff(arr, n-1, sum_cal, sum));*/
	    
	    
	}
	
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum += arr[i];
	    //return mindiff(arr, n, 0, sum);
	    int** dp = new int*[2];
	    for(int i=0;i<2;i++)
	    {
	        dp[i] = new int[sum+1];
	        for(int j=0;j<=sum;j++)
    	        dp[0][j] = 0;
    	    dp[i][0] = 1;
	    }
	    
	    dp[0][0]=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(arr[n-i]<=j)
	                dp[i%2][j] = dp[(i-1)%2][j] or dp[(i-1)%2][j-arr[n-i]];
	            
	            else
	                dp[i%2][j] = dp[(i-1)%2][j];
	        }
	    }
	    
	    int j;
	    for(j=sum/2;j>=0;j--)
	    {
	        if(dp[n%2][j])
	            return sum - 2*j;
	    }
	    return sum - 2*j;
	}
