int Solution::solve(int n, vector<int> &a) 
{
    int i,j, sum=0;
    for(i=0;i<n;i++)
        sum += a[i];
    if(sum%3!=0)
        return 0;
    int r1 = sum/3;
    int ans=0;
    /*int* prefix = new int[n];
    int* suffix = new int[n];
    prefix[0]=a[0], suffix[n-1]=a[n-1];
    for(i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1] + a[i];
        suffix[n-i-1] = suffix[n-i] + a[n-i-1];
    }
    for(i=0;i<n-2;i++)
    {
        if(prefix[i]==r1)
        {
            for(j=i+2;j<n;j++)
            {
                if(suffix[j]==r1)
                    ans++;
            }
        }
    }*/
    int* suffix = new int[n];
    int sumr = 0;
    for(i=n-1;i>=0;i--)
    {
        sumr += a[i];
        if(sumr==r1)
            suffix[i] = 1;
        else
            suffix[i] = 0;
    }
    for(i=n-2;i>=0;i--)
        suffix[i] += suffix[i+1]; 
    sumr=0;
    for(i=0;i<n-2;i++)
    {
        sumr += a[i];
        if(sumr==r1)
            ans += suffix[i+2];
    }
    return ans;
}
