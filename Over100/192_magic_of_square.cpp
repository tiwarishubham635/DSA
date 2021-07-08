long long magic_of_square (int n, vector<long long> arr)
{
  vector<vector<long long>>dp(2, vector<long long>(2,0));
  long long best = INT_MIN;
  dp[0][0] = arr[0];
  dp[0][1] = arr[0]*arr[0];
  for(int i=1;i<n;i++)
  {
     dp[i%2][0] = max(dp[(i-1)%2][0]+arr[i], arr[i]);
     dp[i%2][1] = max(dp[(i-1)%2][1]+arr[i], max(arr[i]*arr[i], dp[(i-1)%2][0]+(arr[i]*arr[i])));
     best = max(best, max(dp[i%2][0], dp[i%2][1]));
  }
  return best;
}
