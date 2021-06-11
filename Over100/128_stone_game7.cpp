int dp[1005][1005] = {}, pre[1005] = {};
int stoneGameVII(vector<int>& A) 
{
    int n = A.size();  
    for(int i=0; i<n; i++) 
        pre[i+1] = A[i] + pre[i];

    for(int l=n-2; l>=0; l--) 
    {
        for(int r = l+1; r<n; r++) 
        {
            int left = pre[r+1] - pre[l+1] - dp[l+1][r]; // dp[l+1][r]
            int right = pre[r] - pre[l] - dp[l][r-1]; // dp[l][r-1]
            dp[l][r] = max(left, right);
        }
    }
    return dp[0][n-1];
}
