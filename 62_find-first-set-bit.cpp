unsigned int getFirstSetBit(int n)
    {
        /*string s = "";
        while(n)
        {
            int ans = n%2;
            s = to_string(ans)+s;
            n=n/2;
        }
        for(int i=s.size()-1;i>=0;i--)
            if(s[i]=='1')
                return s.size()-i;
        return 0;*/
        
        return 1+log2(n&(-n));

        // return ffs(n);
        
        /*if(n==0)
            return 0;
        int pos=1;
        int m=1;
        while(!(n&m))
        {
            m = m << 1;
            pos++;
        }
        return pos;*/
        
        /*int pos=0;
        while(n)
        {
            if(n&1)
                return ++pos;
            pos++;
            n = n>>1;
        }
        return pos;8/
    }
