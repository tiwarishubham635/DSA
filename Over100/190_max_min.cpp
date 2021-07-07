pair<int,int> helper(const vector<int> &arr, int l, int r)
{
    pair<int,int> ans;

    if(l==r)
    {
        ans.first = arr[l];
        ans.second = arr[l];
        return ans;
    }

    if(r==l+1)
    {
        ans.first = (arr[r]>arr[l]?arr[r]:arr[l]);      // max
        ans.second = (ans.first==arr[l]?arr[r]:arr[l]); // min
        return ans;
    }

    int mid = l + (r-l)/2;
    pair<int,int> left = helper(arr, l, mid);
    pair<int,int> right = helper(arr, mid+1, r);

    ans.first = (left.first > right.first?left.first:right.first);
    ans.second = (left.second <= right.second?left.second:right.second);
    return ans;
}

int Solution::solve(vector<int> &A) 
{
    /*int mx = INT_MIN, mn = INT_MAX;
    for(int i=0;i<A.size();i++)
        mx = max(mx, A[i]), mn = min(mn, A[i]);
    return mx+mn;*/
    pair<int,int>p = helper(A, 0, A.size()-1);
    return (p.first+p.second);
}
