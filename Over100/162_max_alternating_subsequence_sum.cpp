long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<ll>>dp(n+1, vector<ll>(2,0));
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]+nums[i]); // 0 means we have to add now
            dp[i][1] = max(dp[i+1][1], dp[i+1][0]-nums[i]); // 1 means we have to subtract now
        }
        return max(dp[0][0], dp[0][1]);
        
        /*vector<ll>dp(2,0);
        ll val0, val1;
        
        for(int i=0;i<n;i++)
        {
            val0 = max(dp[1]+nums[i], dp[0]);
            val1 = max(dp[0]-nums[i], dp[1]);
            dp[0]=val0;
            dp[1]=val1;
        }
        return max(dp[0], dp[1]);*/
        
    }
