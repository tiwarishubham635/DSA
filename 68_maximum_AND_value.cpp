int check(int pattern, int arr[], int n)
	{
	    int ct=0;
	    for(int j=0;j<n;j++)
	       if((arr[j]&pattern)==pattern)
	            ct++;
	    return ct;
	}
	int maxAND (int arr[], int n)
	{
	    int res=0,ct;
	    for(int i=31;i>=0;i--)
	    {
	        ct = check(res|(1<<i), arr, n);
	        if(ct>=2)
	            res = res|(1<<i);
	    }
	    return res;
	}
