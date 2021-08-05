string minWindow(string s, string t) {
        unordered_map<int,int>mp;
        for(int i=0;i<t.size();i++)
            mp[t[i]]++;
        int l=0, r= 0;
        int min_length = INT_MAX;
        int size = 0;
        int start = 0;
        unordered_map<int,int>window;
    
        while(r<s.size())
        {
            window[s[r]]++;
            if(mp.find(s[r])!=mp.end() && window[s[r]]==mp[s[r]])
                size++;
            
            while(l<=r && size==mp.size())
            {
                if(min_length > r-l+1)
                    start = l, min_length = r-l+1;
                window[s[l]]--;
                if(mp.find(s[l])!=mp.end() && window[s[l]] < mp[s[l]])
                    size--;
                l++;
            }
            r++;
        }
        
        return (min_length == INT_MAX? "" : s.substr(start, min_length));
    }
