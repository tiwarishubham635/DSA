int common_length(string x, string y)
    {
        int ct=0;
        int i;
        for(i=0;i<min(x.size(), y.size());i++)
        {
            if(x[i]!=y[i])
                return i;
        }
        return i;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        int* dp = new int[n+1];
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=0;
            for(int j=0;j<wordDict.size();j++)
            {
                int l = common_length(s.substr(i), wordDict[j]);
                if(l==wordDict[j].size())
                    dp[i] = dp[i+l] or dp[i];
            }
        }
        
        return dp[0];
    }
