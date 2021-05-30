int Solution::maxArr(vector<int> &a) 
{
    int m1 = a[0], m2 = a[0];
    for(int i=1;i<a.size();i++)
    {
        if(m1<a[i]-i)
            m1 = a[i]-i;
        if(m2>a[i]-i)
            m2 = a[i]-i;
    }
    
    int m3 = a[0], m4 = a[0];
    for(int i=1;i<a.size();i++)
    {
        if(m3<a[i]+i)
            m3 = a[i]+i;
        if(m4>a[i]+i)
            m4 = a[i]+i;
    }
    
    return max(m1-m2, m3-m4);
}
