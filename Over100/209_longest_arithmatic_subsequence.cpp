int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2000,0));
        int max_len = 2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff = nums[j] - nums[i] + 1000;
                dp[j][diff] = max(2, dp[i][diff]+1);
                max_len = max(max_len, dp[j][diff]);
            }
        }
        return max_len;
    }
