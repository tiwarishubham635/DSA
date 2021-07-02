int Solution::repeatedNumber(const vector<int> &A) 
{
    int n = A.size();
    int a = INT_MAX, b=INT_MAX;
    int ct1=0,ct2=0;
    for(int i=0;i<n;i++)
    {
        if(a==A[i])
            ct1++;
        
        else if(b==A[i])
            ct2++;
        
        else if(ct1==0)
            ct1++, a = A[i];
        
        else if(ct2==0)
            ct2++, b = A[i];
        
        else
            ct1--, ct2--;
    }

    ct1=0, ct2=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==a)
            ct1++;
        if(A[i]==b)
            ct2++;
    }

    if(ct1>n/3)
        return a;
    
    if(ct2>n/3)
        return b;
    
    return -1;
}
