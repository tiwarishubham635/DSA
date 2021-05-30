int countTriplets(int a[], int n, int l, int r) 
    {
        sort(a,a+n);
        int count=0;
        for(int i=0;i<n-2;i++)
        {
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = a[i]+a[j]+a[k];
                if(sum<=r)
                    count+= (k-j), j++;
                else
                    k--;
            }
        }
        
        for(int i=0;i<n-2;i++)
        {
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = a[i]+a[j]+a[k];
                if(sum<l)
                    count-= (k-j), j++;
                else
                    k--;
            }
        }
        
        return count;
    }
