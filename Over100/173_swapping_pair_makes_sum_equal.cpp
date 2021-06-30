/*int findSwapValues(int A[], int n, int B[], int m)
    {
        int sum1 = 0;
        for (int i = 0; i < n; i++)
            sum1 += A[i];
        
        int sum2 = 0;
        for (int i = 0; i < m; i++)
            sum2 += B[i];

        sort(A, A + n);
        sort(B, B + m);
     
        // sum1 - x + y = sum2 - y + x
        // 2(y-x) = sum2 - sum1
        // y - x = (sum2 - sum1)/2 
        // difference of two integers can't be in decimal, so sum2 - sum1 must be even!
        
        if ((sum1 - sum2) % 2 != 0) 
            return -1;
        int target = ((sum1 - sum2) / 2);
     
        int i = 0, j = 0;
        while (i < n && j < m) 
        {
            int diff = A[i] - B[j];
            if (diff == target) 
                return 1;
     
            else if (diff < target)
                i++;
     
            else
                j++;
        }
        return -1;
    }*/
	int findSwapValues(int a[], int n, int b[], int m)
	{
	    if(n>m)
	        return findSwapValues(b, m, a, n);
	        
	    int sa = 0, sb = 0;
	    for(int i=0;i<n;i++)
	        sa += a[i];
	       
	    for(int i=0;i<m;i++)
	        sb += b[i];
	    
	    if((sa-sb)%2!=0)
	        return -1;
	        
	    int target = (sa-sb)/2;
	    unordered_set<int>s;
	    for(int i=0;i<n;i++)
	        s.insert(a[i]);
	    
	    for(int j=0;j<m;j++)
	    {
	        int x = b[j] + target;
	        if(s.find(x)!=s.end())
	            return 1;
	    }
	    return -1;
	}
