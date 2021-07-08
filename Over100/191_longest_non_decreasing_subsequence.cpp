vector<int> LIS (int n, vector<int> arr) 
{
  vector<int>ans;
  vector<int>dp(n+1,INT_MAX);
  dp[0] = INT_MIN;
  for(int i=0;i<n;i++)
  {
     int len = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
     if(dp[len-1]<=arr[i] && dp[len]>arr[i])
        dp[len] = arr[i];
     ans.push_back(len);
  }
  return ans;
}
