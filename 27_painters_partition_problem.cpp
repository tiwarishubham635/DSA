long long no_of_painters(int a[], int n, long long max_len)
{
    long long total=0, painters =1;
    for(long long i=0;i<n;i++)
    {
        total += a[i];
        if(total > max_len)
        {
            total = a[i];
            painters++;
        }
    }
    return painters;
}
long long minTime(int a[], int n, int k)
{
    long long sum = a[0], mx = a[0];
    for(long long i=1;i<n;i++)
    {
        sum += a[i];
        if(mx<a[i])
            mx = a[i];
    }

    while(mx <= sum)
    {
        long long mid = (mx+sum)/2;
        long long p = no_of_painters(a, n, mid);
        if(p<=k)
            sum = mid-1;
        else
            mx = mid+1;
    }
    return mx;
}
