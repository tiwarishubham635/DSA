int maxSubarraySum(vector<int>& sum, int k, int row)
    {  
        int curSum = 0; 
        int curMax = INT_MIN; 

        set<int> sumSet; 
        sumSet.insert(0);

        for (int r = 0; r < row; ++r) 
        {
            curSum += sum[r]; 
            auto it = sumSet.lower_bound(curSum - k); 

            if (it != sumSet.end()) {
                curMax = max(curMax, curSum - *it);
            }

            sumSet.insert(curSum);
        }

        return curMax;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    { 
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        int ans = INT_MIN; 
        vector<int>arr(m); 
        
        for(int row1=0;row1<n;row1++) 
        {
            for(int i=0;i<m;i++)
                arr[i]=0;
            
            for(int row2=row1;row2<n;row2++)
            {
                int curr_max = 0, max_so_far = INT_MIN;
                for(int i=0;i<m;i++)
                {
                    arr[i] += matrix[row2][i];
                    curr_max = max(curr_max+arr[i], arr[i]);
                    max_so_far = max(max_so_far, curr_max);
                }
                
                if(max_so_far==k)
                    return k;
                
                if(max_so_far<=k)
                {
                    ans = max(ans, max_so_far);
                    continue;
                }
                
                ans = max(ans, maxSubarraySum(arr, k, m));
            }
        }
        return ans;
    }
