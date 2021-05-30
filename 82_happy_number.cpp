int next(int n)
    {
        int ans=0;
        while(n)
        {
            ans += (n%10)*(n%10);
            n = n/10;
        }
        return ans;
    }
    bool isHappy(int n) 
    {
        int slow = next(n), fast = next(next(n));
        if(slow==1)
            return true;
        if(fast==1)
            return true;
        while(slow!=fast)
        {
            slow = next(slow);
            fast = next(next(fast));
            if(fast==1)
                return true;
        }
        return false;
    }
