Approach 1:
	
	int binarysearch(vector<int>a, int l, int r, int k)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]==k)
            return mid;
        if(a[mid]<k)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int Search(vector<int> a, int k) 
{
    int n =a.size();
    int l=0, r=n-1, pivot=-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(mid==n-1||a[mid]>a[mid+1])
        {
            pivot = mid;
            break;
        }
        if(mid==0||a[mid]<a[mid-1])
        {
            pivot = mid-1;
            break;
        }
        if(a[l]<a[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    
    if(pivot==-1)
    {
        return binarysearch(a, 0, n-1, k);
    }
    else
    {
        if(a[pivot]==k)
            return pivot;
        
        if(a[0]<=k)
            return binarysearch(a,0, pivot-1,k);
        else
            return binarysearch(a, pivot+1, n-1, k);
    }
}

APPROACH - 2

int Search(vector<int> a, int k) 
{
    int n =a.size();
    int l=0, r=n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]==k)
            return mid;
        if(a[l]<=a[mid])
        {
            if(k>=a[l]&&k<=a[mid])
                r = mid-1;
            else
                l = mid+1;
        }
        else
        {
            if(k>=a[mid+1]&&k<=a[r])
                l = mid+1;
            else
                r = mid-1;
        }
    }
    return -1;
}
