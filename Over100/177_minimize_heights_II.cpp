int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr, arr+n);
        int res = arr[n-1]-arr[0]; // 8
        int mx, mn;
        
        for(int i=1;i<n;i++)
        {
            mx = max(arr[i-1]+k, arr[n-1]-k); // 6
            mn = min(arr[i]-k, arr[0]+k); // -1
            if(mn>mx or mx<0 or mn<0)
                continue;
            res = min(res, mx-mn);
            //cout<<mx<<" "<<mn<<" "<<res<<endl;
        }
        return res;
    }
