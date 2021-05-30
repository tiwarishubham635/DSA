int findPlatform(int arr[], int dep[], int n)
    {
    	/*sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int ans=1,plat=1;
    	while(i<n&&j<n)
    	{
    	    if(arr[i]<=dep[j])
    	        plat++, i++;
    	    else plat--, j++;
    	    ans = max(ans, plat);
    	}*/
    	int* platform = new int[2361];
    	int ans=1;
    	for(int i=0;i<n;i++)
    	{
    	    platform[arr[i]]++;
    	    platform[dep[i]+1]--;
    	}
    	for(int i=1;i<2361;i++)
    	{
    	    platform[i] += platform[i-1];
    	    ans = max(ans, platform[i]);
    	}
    	return ans;
    }
