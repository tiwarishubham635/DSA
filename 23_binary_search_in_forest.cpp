int find_height(int a[], int n, int k)
{
    sort(a, a+n);
    int l=0,r=a[n-1];
    while(l<=r)
    {
        int mid = (l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++)
            if(a[i]>mid)
                sum += a[i]-mid;
        if(sum==k)
            return mid;
        if(sum<k)
            r = mid-1;
        else l = mid+1;
    }
    return -1;
}
