int sum(int a , int b)
{   
    if(b==0)
        return a;
    return sum(a^b, (a&b)<<1);
}
