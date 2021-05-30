int wildCard(string pattern,string str)
    {
        /*if(pattern.size()==0)
        {
            if(str.size()==0)
                return 1;
            else return 0;
        }

        if(pattern[0]=='*')
        {
            if(str.size()==0)
                return true;
            if(pattern.size()==1)
                return true;
            int ans = 0;
            for(int i=0;i<str.size();i++)
                ans = ans || wildCard(pattern.substr(1), str.substr(i));
            return ans;
        }
        if(pattern[0]==str[0] || pattern[0]=='?')
        {
            return wildCard(pattern.substr(1), str.substr(1));
        }
        else return false;*/
        
        int n = str.size(), m = pattern.size();
        int** dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] = new int[m+1];
            dp[i][0] = 0;
        }
        dp[0][0]=1;
        
        for(int j=1;j<=m;j++)
            dp[0][j] = dp[0][j-1] && (pattern[m-j]=='*');
            
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(pattern[m-j]=='*')
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                else if(pattern[m-j]==str[n-i] || pattern[m-j]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }
        
        return dp[n][m];
    }
