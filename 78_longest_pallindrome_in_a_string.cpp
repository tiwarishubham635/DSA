string longestPalindrome(string s)
    {
        int n = s.size();
        /*int **dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        }
        
        int start=0, maxlen=1;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(k==2&&s[i]==s[j])
                {
                    if(maxlen!=k)
                        start = i;
                    dp[i][j]=1;
                    maxlen=k;
                }
                else if(dp[i+1][j-1]&&s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k>maxlen)
                    {
                        start = i;
                        maxlen = k;
                    }
                }
            }
        }
        return s.substr(start,maxlen);*/
        
        int maxlen=1,start=0;
        for(int i=1;i<n;i++)
        {
            int low = i-1;
            int high = i+1;
            while(low>=0&&high<n&&s[low]==s[high])
            {
                if(high-low+1>maxlen)
                {
                    start=low;
                    maxlen=high-low+1;
                }
                low--;
                high++;
            }
            
            low = i-1;
            high=i;
            while(low>=0&&high<n&&s[low]==s[high])
            {
                if(high-low+1>maxlen)
                {
                    start=low;
                    maxlen=high-low+1;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, maxlen);
    }
