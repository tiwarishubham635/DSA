int CountWays(string str)
	{
	    /*if(str.size()==0 || str.size()==1&&str[0]!='0')
		return 1;

	    if(str[0]=='0')
		return 0;

	    if((str[0]-'0')*10+(str[1]-'0')<=26)
		return CountWays(str.substr(1))+CountWays(str.substr(2));

	    return CountWays(str.substr(1));*/
	    int n = str.size();
	    long long* dp = new long long[n+1];
	    int mod = 1000000007;
	    dp[0]=1;
	    if(str[n-1]!='0')
		dp[1]=1;
	    else dp[1]=0;
	    for(int i=2;i<=n;i++)
	    {
		if(str[n-i]=='0')
		    dp[i]=0;
		else if((str[n-i]-'0')*10+(str[n-i+1]-'0')<=26)
		    dp[i]=(dp[i-1]+dp[i-2])%mod;
		else dp[i]=dp[i-1];
	    }
	    return dp[n];
	}
