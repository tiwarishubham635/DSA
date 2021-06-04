long long findNth(long long n)
{
    long long ans =0;
    long long p = 1;
    while(n)
    {
        ans += p*(n%9);
        p *= 10;
        n = n/9;
    }
    return ans;
}
