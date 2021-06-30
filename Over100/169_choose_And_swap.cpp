string chooseandswap(string str)
    {
        int n = str.size();
        int i,j;
        
        unordered_map<char,int>mp;
        for(i=0;i<n;i++)
            if(mp.find(str[i]-'a')==mp.end())
                mp[str[i]-'a']=i;
        
        for(i=0;i<n;i++)
        {
            int f=0;
            for(j=0;j<str[i]-'a';j++)
            {
                if(mp[j]>mp[str[i]-'a'])
                {
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        
        if(i<n)
        {
            char c1 = str[i];
            char c2 = (char)('a'+j);
            
            for(j=0;j<n;j++)
            {
                if(str[j]==c1)
                    str[j]=c2;
                else if(str[j]==c2)
                    str[j]=c1;
            }
        }
        return str;
    }
