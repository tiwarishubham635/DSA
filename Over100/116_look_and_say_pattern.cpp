string lookandsay(int n) 
    {
        string x = "1";
        if(n==1)
            return x;
        
        for(int i=2;i<=n;i++)
        {
            x += '&';
            int len = x.size();
            int c=1;
            string tmp = "";
            
            for(int i=1;i<len;i++)
            {
                if(x[i]==x[i-1])
                    c++;
                
                else
                {
                    tmp += (c+'0');
                    tmp += x[i-1];
                    c = 1;
                }
            }
            
            x = tmp;
        }
        return x;
    }   
