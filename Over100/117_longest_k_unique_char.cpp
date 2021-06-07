int longestKSubstr(string s, int k) 
    {
        int n = s.size();
        int* count = new int[26];
        for(int i=0;i<26;i++)
            count[i]=-1;
        int u=0;
        for(int i=0;i<n;i++)
        {
            if(count[s[i]-'a']==-1)
            {
                u++;
                count[s[i]-'a'] = i;
            }
        }
        if(u<k)
            return -1;
        if(u==k)
            return n;
        for(int i=0;i<26;i++)
            count[i]=0;
        int start = 0, end = 1;
        int max_size=0;
        count[s[start]-'a']++;
        while(end<n)
        {
            count[s[end]-'a']++;
            end++;
            
            int ct=0;
            for(int i=0;i<26;i++)
                if(count[i]!=0)
                    ct++;
            while(ct>k)
            {
                count[s[start]-'a']--;
                if(count[s[start]-'a']==0)
                    ct--;
                start++;
            }
            
            if(end-start>max_size)
                max_size=end-start;
        }
        return max_size;
    }
