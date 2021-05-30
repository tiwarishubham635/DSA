 O(nlogn) Approach
long long int fact(long long int n)
{
    long long int f = 1;
    for(long long int i=2;i<=n;i++)
        f = (f*i)%1000000007;
    return f;
}

long long int power(long long int a, long long int b)
{
    if(b==0)
        return 1;
        
    if(b==1)
        return a;
    long long int tmp = (power(a, b/2))%1000000007;
    if(b%2==0)
        return (tmp*tmp)%1000000007;
    return (((a*tmp)%1000000007)*tmp)%1000000007;
}

int Solution::solve(int m, vector<int> &a) 
{
    int n = a.size(); int mod = 1000000007;
    sort(a.begin(), a.end());
    vector<int>b;
    b.push_back(a[0]-1);
    for(int i=1;i<n;i++)
        b.push_back(a[i]-a[i-1]-1);
    b.push_back(m-a[n-1]);
    long long ans = fact(m-n);
    for(int i=0;i<b.size();i++)
        ans = (ans*(power(fact(b[i]), mod-2))%mod)%mod; 
    for(int i=1;i<b.size()-1;i++)
    {
        if(b[i]>1)
            ans = (ans*(power(2, b[i]-1))%mod)%mod;       
    }
    return ans%mod;
}
