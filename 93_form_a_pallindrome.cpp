int findMinInsertions(string s)
{
    int n = s.size();
    /*if(n==0 or n==1)
        return 0;
    if(n==2)
        return !(s[0]==s[1]);
    if(s[n-1]==s[0])
        return findMinInsertions(s.substr(1,n-2));
    return 1+min(findMinInsertions(s.substr(0,n-1)), findMinInsertions(s.substr(1,n-1)));*/


    /*int** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n-i+1];
        dp[i][0]=0;
        if(i!=n)
            dp[i][1]=0;
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=2;j<=(n-i);j++)
        {
            if(j==2)
                dp[i][j]=!(s[i]==s[i+1]);

            else
            {
                if(s[i]==s[i+j-1])
                    dp[i][j]=dp[i+1][j-2];

                else
                    dp[i][j]=1+min(dp[i][j-1], dp[i+1][j-1]);
            }
        }
    }
    return dp[0][n];*/

    string rev="";
    for(int i=n-1;i>=0;i--)
        rev += s[i];

    //LCS of s and rev
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n+1];
        dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[n-i]==rev[n-j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n-dp[n][n];
}
