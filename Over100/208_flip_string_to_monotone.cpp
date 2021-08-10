int minFlipsMonoIncr(string s) {
        /*int ones=0, flips=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                ones++;
            else
                flips++;
            flips = min(flips, ones);
        }
        return flips;*/
        int n = s.size();
        int f0=0,f1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                f0++, f1 = min(f0, f1);
            else
                f1 = min(f0, f1+1);
        }
        return f1;
    }
