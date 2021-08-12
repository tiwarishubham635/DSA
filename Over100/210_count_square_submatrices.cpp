int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        int sq=0;
        for(int i=0;i<n;i++)
            dp[i][0] = matrix[i][0], sq += dp[i][0];
        
        for(int i=1;i<m;i++)
            dp[0][i] = matrix[0][i], sq += dp[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j])
                {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    sq += dp[i][j];
                }
            }
        }
        
        return sq;
    }
