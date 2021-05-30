int lcs(string s1,string s2, int n, int m, int count)
    {
        if(n==0)
            return count;
        if(m==0)
            return count;
        if(s1[n-1]==s2[m-1])
            count = lcs(s1, s2, n-1, m-1, count+1);
        count = max(count, max(lcs(s1,s2,n-1,m,0), lcs(s1,s2,n,m-1,0)));
        return count;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        /*int count=0;
        return lcs(S1, S2, n, m, count);*/
        
        int** dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
            dp[i][0]=0;
            for(int j=0;j<=m;j++)
                dp[0][j]=0;
        }
        
        int ans = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1], ans = max(ans, dp[i][j]);
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
