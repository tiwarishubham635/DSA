O(n2) solution
int canReach(int a[], int n) 
    {
        int* dp = new int[n];
        dp[0] = 1; // dp[i] denotes if we can reach index i from index 0
                    // for jumps to reach, dp[0] = 0
        for(int i=1;i<n;i++)
        {
            dp[i] = 0; // for jumps dp[i] = INT_MAX
            for(int j =0; j<i;j++)
            {
                if(i<=j+a[j]&&dp[j]!=0)
                {
                    dp[i] = 1; // for jumps dp[i] = max(dp[i], dp[j]+1)
                    break;
                }
            }
        }
        return dp[n-1];
    }
	O(N) Approach:

int canReach(int a[], int n) 
    {
       if(n<=1)
        return 1; // 0 jumps required
        
        if(a[0]==0)
            return 0; // not possible to reach
            
        int maxReach = a[0], steps = a[0], jumps = 1; // steps = no. of steps which are 
                                                      // left to be taken
        for(int i=1; i<n;i++)
        {
            if(i==n-1)
                return 1; //return jumps;
            
            maxReach = max(maxReach, i+a[i]);
            steps--;
            if(steps==0)
            {
                jumps++;
                
                if(i>=maxReach)
                    return 0; // return -1; // not possible to move forawrd from index i
                
                steps = maxReach - i;
            }
        }
        return 1;
    }
