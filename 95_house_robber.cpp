int helper(vector<int>&nums, int s, int e)
    {
        if(s==e or s+1==e)
            return nums[s];
        
        int m = INT_MIN;
        for(int i=s+2;i<=e;i++)
        {
            int val = helper(nums, i, e);
            m = max(m, nums[s]+val);
        }
        
        return m;
    }
    
    int rob(vector<int>& nums) 
    {
        /*int s = 0, e = nums.size()-1;
        return max(helper(nums, s, e), helper(nums, s+1, e));*/
        
        int n = nums.size();
        /*if(n==1)
            return nums[0];
        
        int* dp = new int[n];
        dp[n-1]=nums[n-1];
        dp[n-2]=nums[n-2];
        
        for(int i=n-3;i>=0;i--)
        {
            dp[i]=INT_MIN;
            for(int j=i+2;j<n;j++)
                dp[i]=max(dp[i], nums[i]+dp[j]);
        }
        
        return max(dp[0], dp[1]);*/
        
        int a=0, b=0;
        for(int i=0;i<n;i++)
        {
            if(i%2)
            {
                a = max(a+nums[i], b);
            }
            else
            {
                b=max(b+nums[i], a);
            }
        }
        return max(a,b);
    }
