long long merge(long long arr[], long long tmp[], long long left, long long mid, long long right)
    {
        long long i, j, k;
        long long ans = 0;
        for (i = left, j = mid, k = left; i <= mid-1 && j <= right;)
        {
            if (arr[i] <= arr[j])
                tmp[k++] = arr[i++];
            
            else
            {
                tmp[k++] = arr[j++];
                ans += (mid-i);
            }
        }

        while (i <= mid-1)
        {
            tmp[k++] = arr[i++];
        }
    
        while (j <= right)
        {
            tmp[k++] = arr[j++];
        }
        
    
        for (long long i = left; i <= right; i++)
            arr[i] = tmp[i];
        
        return ans;
    }
    
    long long mergesort(long long arr[], long long start, long long end, long long tmp[])
    {
        if (start >= end)
            return 0;
    
        long long mid = (start + end) / 2;
        long long ans = mergesort(arr, start, mid, tmp);
        ans += mergesort(arr, mid + 1, end, tmp);
        ans += merge(arr, tmp, start, mid+1, end);
        return ans;
    }
    
    long long inversionCount(long long arr[], long long n)
    {
        long long* tmp = new long long[n];
        for (long long i = 0; i < n; i++)
            tmp[i] = arr[i];
        return mergesort(arr, 0, n - 1, tmp);
    }
