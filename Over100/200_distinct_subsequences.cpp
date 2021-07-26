#include<bits/stdc++.h>
int mod = 1e9+7;
int distinctSubsequences(string s) 
{
    long long n = s.size();
    long long allCount = 0, levelCount = 0;
    //vector<long long>dp(n+1, 0); // dp[i] = no. of distinct subsequences of length i
    unordered_map<char,long long>last_index;
    //dp[0] = 1;
    
    //long long ans = 0;
    /*for(long long i=1;i<=n;i++)
    {
        dp[i] = (2*dp[i-1])%mod;
        if(last_index.find(s[i-1])!=last_index.end())
            dp[i] = (mod + dp[i] - dp[last_index[s[i-1]]])%mod;
        last_index[s[i-1]] = i-1;
        dp[i] %= mod;
    }
    return dp[n]%mod;*/
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            allCount = 1;
            levelCount = 1;
            last_index[s[i]] = 1;
            continue;
        }
        levelCount = (allCount+1)%mod;
        if(last_index.find(s[i])==last_index.end())
            allCount = (levelCount + allCount)%mod;
        else
            allCount = ((levelCount + allCount)%mod + mod - last_index[s[i]])%mod;
        last_index[s[i]] = levelCount;
    }
    return (allCount+1)%mod;
}
