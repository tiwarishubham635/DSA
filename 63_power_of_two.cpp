bool isPowerofTwo(long long n)
    {
        /*long long m =1;
        while(n>=m)
        {
            if(n==m)
                return true;
            m = m << 1;
        }
        return false;*/
        
        return n&&(!(n&(n-1)));
        
        //method to count set bits
        
        /*int ct=0;
        while(n)
        {
            n &= (n-1);
            ct++;
        }
        return (ct==1);*/
    }
