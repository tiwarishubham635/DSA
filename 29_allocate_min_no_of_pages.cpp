bool possible(int a[], int n, int max_len, int m)
    {
        int total=0, students = 1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>max_len)
                return 0;
            total += a[i];
            if(total > max_len)
            {
                total = a[i];
                students++;
                if(students>m)
                    return 0;
            }
        }
        return 1;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        long long sum=a[0];
        for(int i=1;i<n;i++)
        {
            sum += a[i];
        }
        int mx = 0;
        int result = INT_MAX;
        while(mx<=sum)
        {
            int mid = (mx + sum)/2;
            
            if(possible(a, n, mid, m))
                result = min(result, mid), sum = mid-1;
                
            else
                mx = mid+1;
        }
        return result;
    }
