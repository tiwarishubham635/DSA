int isPallindrome(string x)
    {
        for(int i=0;i<x.size()/2;i++)
            if(x[i]!=x[x.size()-1-i])
                return false;
        return true;
    }
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        /*if(n==0 or n==1)
            return 0;
            
        if(isPallindrome(str))
            return 0;
        
        int m = 1+palindromicPartition(str.substr(0,n-1));
        
        for(int i=n-2;i>0;i--)
        {
            if(isPallindrome(str.substr(i,n-i)))
            m = min(m, 1+palindromicPartition(str.substr(0,i)));
        }
        
        return m;*/
        
        /*int** dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n-i+1];
            dp[i][0]=0;
            if(i!=n)
                dp[i][1]=1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=(n-i);j++)
            {
                if(isPallindrome(str.substr(i,j)))
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=1+dp[i][j-1];
                    for(int k=j-2;k>0;k--)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k]+1+dp[i+k][j-k]);
                    }
                }
            }
        }
        return dp[0][n];*/
        
        int* cut = new int[n];
        bool** p = new bool*[n];
        for(int i=0;i<n;i++)
        {
            p[i]=new bool[n];
            for(int j=0;j<n;j++)
                p[i][j]=0;
        }
        
        for(int i=0;i<n;i++)//length of array
        {
            int mincut = i;
            for(int j=0;j<=i;j++)//starting point
            {
                if((str[j]==str[i])&&(((i-j)<=1)or p[j+1][i-1]))
                {
                    p[j][i]=1;
                    mincut = min(mincut,((j==0)?0:cut[j-1]+1));
                }
            }
            cut[i]=mincut;
        }
        return cut[n-1];
    }
