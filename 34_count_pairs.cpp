long long pair(int x, int b[], int m, long long* y)
    {
        if(x==0)
            return 0;
        if(x==1)
            return y[0];
        long long idx=(b+m)-upper_bound(b,b+m,x);
        idx += (y[0]+y[1]);
        if (x == 2)
		    idx -= (y[3] + y[4]);

    	if (x == 3)
    		idx += y[2];
    
    	return idx;
    }
    
    long long countPairs(int a[], int b[], int n, int m)
    {
       sort(b,b+m);
       long long count=0;
       
       long long* y = new long long[5];
       for(long long i=0;i<m;i++)
        if(b[i]<5)
            y[b[i]]++;
            
       for(long long i=0;i<n;i++)
        count += pair(a[i], b, m, y);
       return count;
    }
