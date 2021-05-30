pair<long,long> indexes(vector<long long> v, long long x)
{
    pair<long,long>ans;
    ans.first=-1,ans.second=-1;
    long long n = v.size();
    long long l =0, r=n-1;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        if((mid==0||v[mid-1]<x)&&v[mid]==x)
        {
            ans.first = mid;
            break;
        }
        if(v[mid]<x)
            l = mid+1;
        else
            r = mid-1;
    }
    l=0,r=n-1;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        if((mid==n-1||v[mid+1]>x)&&v[mid]==x)
        {
            ans.second = mid;
            break;
        }
        if(v[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return ans;
}
