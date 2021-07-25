int findIntegers(int n) {
        vector<int>dp(32);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= 31; i++) 
            dp[i] = dp[i-1]+dp[i-2];
        int shift = 31, prebit = 0, ans = 0;
        while (shift >= 0) 
        {
            //whether the first bit is 1
            if (n & 1<<shift) 
            {
                ans += dp[shift];
                if (prebit) 
                    return ans;
                prebit = 1;
            }
            else prebit = 0;
            shift--;
        }
        return ans+1;
    }
