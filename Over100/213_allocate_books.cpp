bool atMostMidBooks(vector<int> &a, int limit, int k)
{
    int children = 1;
    long long booksOfChild = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>limit)
            return false;
        
        if(booksOfChild + a[i] > limit)
        {
            children++, booksOfChild = a[i];
            if(children>k)
                return false;
        }
        
        else
            booksOfChild += a[i];
    }

    return true;
}

int Solution::books(vector<int> &a, int b) {
    int n = a.size();
    if(b>n)
        return -1;
    
    int mx = a[0];
    long long sum = a[0];
    for(int i=1;i<n;i++)
        mx = max(mx, a[i]), sum += a[i];
    //cout<<endl;
    if(b==n)
        return mx;
    
    long long low = 0, high = sum;
    long long ans = INT_MAX;
    while(low<=high)
    {
        long long mid = low + (high - low)/2;
        if(atMostMidBooks(a, mid, b))
            ans = min(ans, mid), high = mid-1;
        else
            low = mid+1;
    }

    return ans;
}
