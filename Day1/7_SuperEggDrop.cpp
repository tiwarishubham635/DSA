// Question: https://leetcode.com/problems/super-egg-drop/

class Solution {
public:
    int max_no_of_floors_that_can_be_solved(int mid, int k, int n)
    {
        int sum = 0;
        int term = 1;
        for(int i=1; i<= k; i++)
        {
            term *= (mid-i+1);
            term /= i;
            
            sum += term;
            if(sum > n) // to avod overflow
                return sum;
        }
        return sum;
    }
  
    int superEggDrop(int k, int n) {
        /*
        Approach - 1: DP 
        If we drop from any floor f, there will be two possibilities:
        1. Egg breaks - then we have k-1 eggs and we have to check in the f-1 floors below only
        2. Egg does not break - then we have k eggs and we have to check in n-f floors above only
        We will consider the maximum of these two (for worst case, guranteed work)
        Then we will find this value for all floors. The minimum of all these value will be our answer. 
        
        vector<vector<int>>dp(k+1, vector<int>(n+1, INT_MAX));
        for(int i=0;i<=k;i++)
            dp[i][0] = 0, dp[i][1] = 1;
        
        for(int i=1;i<=n;i++)
            dp[1][i] = i;
        
        for(int i=2;i<=k;i++)
        {
            for(int j=2;j<=n;j++)
            {
                for(int x=1;x<=j;x++)
                {
                    int eggBreak = dp[i-1][x-1];
                    int eggNotBreak = dp[i][j-x];
                    int worstCase = 1 + max(eggBreak, eggNotBreak);
                    dp[i][j] = min(dp[i][j], worstCase);
                }
            }
        }
        
        return dp[k][n];
        
        */
        
        // Approach - 2: Binary search
        /*
        Here, we will apply binary search on the no. of trials.
        Max no. of trials = n and min = 1
        Now, with binary search we will calculate the max no. of floors that can be solved with given no. of trials i.e. mid
        If no. of floors can be solved < n, then we need more tries as we may have to solve all the floors
        Else we will reduce the upper limit to get the smallest no. of tries which statisfies this condition.
        The 
        max no. of floors that can be solved with given no. of trials x = sum of xCi for 1<=i<=k
        */
      
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(max_no_of_floors_that_can_be_solved(mid, k, n) < n)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
