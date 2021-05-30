int maxSumIS_h(int arr[], int n, int& max)  
	{  
	    if(n==1)
	    {
	        if(max<arr[0])
	            max=arr[0];
	        return arr[0];
	    }
	    
	    int ans = arr[n-1];
	    for(int i=1;i<n;i++)
	    {
	        int val = maxSumIS_h(arr, i, max);
	        if(arr[i-1]<arr[n-1]&&ans < arr[n-1]+val)
	            ans = arr[n-1]+val;
	    }
	    if(ans>max)
	        max = ans;
	    return ans;
	}  
	int maxSumIS(int arr[], int n)
	{
	    /*int max=arr[0];
	    int ans = maxSumIS_h(arr, n, max);
	    return max;*/
	    
	    int* dp = new int[n+1];
	    dp[1]=arr[0];
	    for(int i=2;i<=n;i++)
	    {
	        dp[i]=arr[i-1];
	        for(int j=1;j<i;j++)
	        {
	            if(arr[j-1]<arr[i-1]&&dp[i]<arr[i-1]+dp[j])
	                dp[i]=arr[i-1]+dp[j];
	        }
	    }
	    int mx=INT_MIN;
	    for(int i=1;i<=n;i++)
	        mx = max(mx, dp[i]);
	    return mx;
	}
