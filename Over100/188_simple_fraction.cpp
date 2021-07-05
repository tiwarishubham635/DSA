string fractionToDecimal(int n, int d) 
	{
	    // n = 1, d = 6
        unordered_map<int,int>m;
        int q = n/d;
        string ans=to_string(q);
        int r=0;
        if(n%d==0)
        {
            return ans;
        }
        else
        {
            // m 
            // 1 -> 2, 4->3
            ans+='.'; // 0.1
            r=n%d;    // 40
                      // q = 6
            while(r!=0)
            {
                if(m.find(r)!=m.end())
                {
                    int l=m[r];
                    ans.insert(l,"(");
                    ans+=")";
                    break;
                }
                else
                {
                    m[r]=ans.length();
                    r*=10;
                    q=r/d;
                    r=r%d;
                    ans = ans+to_string(q);
                }
                
            }
        }
        
        return ans;
    }
