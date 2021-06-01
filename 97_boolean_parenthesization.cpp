int dp[201][201][2];
    int total_evaluator(string s, int start, int end)
    {
        return (false_evaluator(s, start, end) + true_evaluator(s, start, end))%1003;
    }

    int false_evaluator(string s, int start, int end)
    {
        if(start==end)
            return (s[start]=='F'?1:0);
        
        int ans=0;
        for(int i=start+1;i<end;i+=2)
        {
            if(s[i]=='|')
                ans += false_evaluator(s,start,i-1)*false_evaluator(s,i+1,end);
            
            if(s[i]=='&')
                ans += (total_evaluator(s,start,i-1)*total_evaluator(s,i+1,end) - true_evaluator(s,start,i-1)*true_evaluator(s,i+1,end));
            
            if(s[i]=='^')
                ans += (true_evaluator(s,start,i-1)*true_evaluator(s,i+1,end) + false_evaluator(s,start,i-1)*false_evaluator(s,i+1,end));
        
            ans%=1003;
        }
        
        return ans%=1003;
    }

    int true_evaluator(string s, int start, int end)
    {
        if(start==end)
            return (s[start]=='T'?1:0);
        
        int ans=0;
        for(int i=start+1;i<end;i+=2)
        {
            if(s[i]=='&')
                ans += true_evaluator(s,start,i-1)*true_evaluator(s,i+1,end);
            
            if(s[i]=='|')
                ans += (total_evaluator(s,start,i-1)*total_evaluator(s,i+1,end) - false_evaluator(s,start,i-1)*false_evaluator(s,i+1,end));
            
            if(s[i]=='^')
                ans += (true_evaluator(s,start,i-1)*false_evaluator(s,i+1,end) + false_evaluator(s,start,i-1)*true_evaluator(s,i+1,end));
            
            ans%=1003;
        }
        
        return ans%=1003;
    }
    
    int parenthesis_count(string s, int i, int j, int isTrue)
    {
        // Base Condition
        if (i > j)
            return false;
        if (i == j) {
            if (isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
     
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue]%1003;
        int ans = 0;
        for (int k = i + 1
             ; k <= j - 1; k = k + 2)
        {
            int leftF, leftT, rightT, rightF;
            if (dp[i][k - 1][1] == -1)
            {
                leftT = parenthesis_count(s, i, k - 1, 1);
            } // Count no. of T in left partition
            else {
                leftT = dp[i][k - 1][1];
            }
     
            if (dp[k + 1][j][1] == -1)
            {
                rightT = parenthesis_count(s, k + 1, j, 1);
            } // Count no. of T in right partition
            else
            {
                rightT = dp[k + 1][j][1];
            }
     
            if (dp[i][k - 1][0] == -1)
            {
                // Count no. of F in left partition
                leftF = parenthesis_count(s, i, k - 1, 0);
            }
            else
            {
                leftF = dp[i][k - 1][0];
            }
     
            if (dp[k + 1][j][0] == -1)
            {
                // Count no. of F in right partition
                rightF = parenthesis_count(s, k + 1, j, 0);
            }
            else
            {
                rightF = dp[k + 1][j][0];
            }
     
            if (s[k] == '&')
            {
                if (isTrue == 1)
                    ans += (leftT * rightT)%1003;
                else
                    ans += (leftF * rightF)%1003 + (leftT * rightF)%1003
                           + (leftF * rightT)%1003;
            }
            else if (s[k] == '|')
            {
                if (isTrue == 1)
                    ans += (leftT * rightT)%1003 + (leftT * rightF)%1003
                           + (leftF * rightT)%1003;
                else
                    ans += (leftF * rightF)%1003;
            }
            else if (s[k] == '^')
            {
                if (isTrue == 1)
                    ans += (leftF * rightT)%1003 + (leftT * rightF)%1003;
                else
                    ans += (leftT * rightT)%1003 + (leftF * rightF)%1003;
            }
            dp[i][j][isTrue] = ans%1003;
        }
        return ans%1003;
    }
    
    int countWays(int n, string s)
    {
        /*int mod=1003;
        int** t = new int*[n];
        int** f = new int*[n];
        
        for(int i=0;i<n;i++)
        {
            t[i]=new int[n];
            f[i]=new int[n];
            t[i][i] = (s[i]=='T');
            f[i][i] = (s[i]=='F');
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                t[i][j]=0, f[i][j]=0;
                for(int k=i+1;k<j;k=k+2)
                {
                    int lT = t[i][k-1];
                    int rT = t[k+1][j];
                    int lF = f[i][k-1];
                    int rF = f[k+1][j];
                    
                    //if(i==0&&j==n-1)
                    //    cout<<lT<<" "<<rT<<" "<<lF<<" "<<rF<<endl;
                    
                    if(s[k]=='&')
                    {
                        t[i][j] += (lT*rT)%mod;
                        f[i][j] += ( (lF*rF)%mod + (lT*rF)%mod + (lF*rT)%mod  )%mod;
                    }
                    
                    if(s[k]=='|')
                    {
                        f[i][j] += (lF*rF)%mod;
                        t[i][j] += ( (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod  )%mod;
                    }
                    
                    if(s[k]=='^')
                    {
                        t[i][j] += ( (lT*rF)%mod + (lF*rT)%mod )%mod;
                        f[i][j] += ( (lT*rT)%mod + (lF*rF)%mod )%mod;
                    }
                    t[i][j] %= mod;
                    f[i][j] %= mod;
                    
                    //    cout<<k<<" "<<t[i][j]<<" ";
                }
            }
        }
        
        return t[0][n-1];*/
        
        memset(dp, -1, sizeof(dp));
        return parenthesis_count(s, 0, n - 1, 1);
    }
