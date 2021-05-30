bool compare(val v1, val v2)
	{
	    return (v1.first < v2.first);
	}

	int helper(struct val p[], int n)
	{
	    if(n==1)
		return 1;

	    int ans = 1;
	    for(int i=1;i<n;i++)
	    {
		if(p[0].second < p[i].first&&ans<1+helper(p+i,n-i))
		    ans = 1+helper(p+i, n-i);
	    }

	    for(int i=1;i<n;i++)
		ans = max(ans, helper(p+i,n-i));

	    return ans;
	}

	int maxChainLen(struct val p[], int n)
	{
	    sort(p, p+n, compare);
	    //return helper(p, n);

	    int* dp = new int[n+1];
	    dp[0]=0;
	    dp[1]=1;

	    for(int i=2;i<=n;i++)
	    {
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
		    if(p[n-i].second < p[n-i+j].first && dp[i]<1+dp[i-j])
			dp[i] = 1+ dp[i-j];
		}
		for(int j=1;j<i;j++)
		    dp[i] = max(dp[i], dp[i-j]);
	    }
	    return dp[n];
	}
