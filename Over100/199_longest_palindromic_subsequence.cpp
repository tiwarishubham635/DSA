#include<bits/stdc++.h>

int helper(string s, string tmp, vector<unordered_map<string,int>>&dp)
{
    int n = s.size();
    if(dp[n].find(tmp)!=dp[n].end())
        return dp[n][tmp];
    if(n==0)
    {
        int i;
        for(i=0;i<tmp.size()/2;i++)
            if(tmp[i]!=tmp[tmp.size()-1-i])
                break;
        int val;
        if(i<tmp.size()/2)
            val = 0;
        else
            val = tmp.size();
        
        dp[0][tmp] = val;
    }
    
    int ans1 = helper(s.substr(1),tmp, dp);
    int ans2 = helper(s.substr(1), tmp+s[0], dp);
    
    int val=max(ans1,ans2);
    dp[n][tmp] = val;
    return val;
}

int longestPalindromeSubsequence(string s)
{
    //string tmp = "";
    //vector<unordered_map<string,int>>dp(101);
    //return helper(s, tmp, dp);
    
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n,0));
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    
    for (int i=n-2; i>=0; i--)
    {
        for (int j=i+1; j<n; j++)
        {
            if (s[i] == s[j] && j-i == 1)
               dp[i][j] = 2;
            else if (s[i] == s[j])
               dp[i][j] = dp[i+1][j-1] + 2;
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
    
    return dp[0][n-1];
}
