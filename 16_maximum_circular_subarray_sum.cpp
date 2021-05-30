 Approach 1

int kadane(int a[], int n)
    {
        int curr_max = a[0], best = a[0];
        for(int i=1;i<n;i++)
        {
            curr_max = max(a[i], curr_max+a[i]);
            best = max(curr_max, best);
        }
        return best;
    }
    int circularSubarraySum(int arr[], int n)
    {
        int ans1 = kadane(arr, n);
        if(ans1 < 0)
            return ans1;
        
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            arr[i] *= -1;
        }
        
        int ans2 = sum + kadane(arr, n);
        return max(ans1, ans2);
    }

Approach 2

int circularSubarraySum(int arr[], int n)
    {
        if(n==1)
            return arr[0];
        int curr_max=arr[0], max_so_far = arr[0], curr_min=arr[0], min_so_far = arr[0], sum = arr[0];
        for(int i=1;i<n;i++)
        {
            sum += arr[i];
            curr_max = max(arr[i], curr_max+arr[i]);
            max_so_far = max(curr_max, max_so_far);
            
            curr_min = min(arr[i], curr_min+arr[i]);
            min_so_far = min(curr_min, min_so_far);
        }
        if(min_so_far==sum)
            return max_so_far;
        return max(max_so_far, sum-min_so_far);
    }

