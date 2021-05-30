int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr+n);
        int count=0;
        
        // Approach 1
        
        /*for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n;j++)
            {
                while(k<n&&arr[i]+arr[j]>arr[k])
                    k++;
                
                if(k>j)
                    count += (k-1)-j;
            }
        }*/
        
        // Approach 2
        for(int i=n-1;i>1;i--)
        {
            int l = 0, r = i-1;
            while(l<r)
            {
                if(arr[l]+arr[r]>arr[i])
                {
                    count += r-l;
                    r--;
                }
                else
                    l++;
            }
        }
        return count;
    }
