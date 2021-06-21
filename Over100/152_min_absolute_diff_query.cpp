vector<int> minDifference(vector<int>& A, vector<vector<int>>& Q) 
    {
        vector<int> ans(Q.size());
        int n = A.size(), m = Q.size();
        int** prefix_freq = new int*[n];
        for(int i=0;i<n;i++)
        {
            prefix_freq[i] = new int[101];
            for(int j=0;j<101;j++)
                prefix_freq[i][j] = ((i==0) ? 0 : prefix_freq[i-1][j]);
            
            prefix_freq[i][A[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            int l = Q[i][0], r = Q[i][1];
            int* count = new int[101];
            for(int j=0;j<101;j++)
                count[j] = prefix_freq[r][j]-((l==0)?0:prefix_freq[l-1][j]);
            
            int prev = -1, diff = INT_MAX;
            for(int j=1;j<101;j++)
            {
                if(count[j]==0)
                    continue;
                if(prev!=-1&&j-prev<diff)
                    diff = j-prev;
                prev=j;
            }
            ans[i] = (diff==INT_MAX)?-1:diff;
        }
        return ans;
    }
