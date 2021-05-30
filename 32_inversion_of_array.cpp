long long int mergesort(long long arr[], long long start, long long end, long long tmp[])
    {
        if (start >= end)
            return 0;
    
        long long int mid = (start + end) / 2;
        long long int ans = mergesort(arr, start, mid, tmp);
        ans += mergesort(arr, mid + 1, end, tmp);
    
        long long i, j, k;
        for (i = start, j = mid, k = start; i <= mid && j <= end;)
        {
            if (arr[i] <= arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
                tmp[k++] = arr[j++];
                ans += (mid+1-i);
            }
        }

        if (i <= mid)
        {
            while (i <= mid)
            {
                tmp[k++] = arr[i++];
            }
        }
    
    
        if (j <= end)
        {
            while (j <= end)
            {
                tmp[k++] = arr[j++];
            }
        }
    
        for (int i = start; i <= end; i++)
            arr[i] = tmp[i];
    
        /*for (int i = start; i <= end; i++)
            cout << arr[i] << " ";
        cout << endl;*/
        return ans;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        long long* tmp = new long long[n];
        for (long long i = 0; i < n; i++)
            tmp[i] = arr[i];
        return mergesort(arr, 0, n - 1, tmp);
    }
