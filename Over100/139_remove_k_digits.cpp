void helper(string s, int k, string &res)
    {
        int n = s.size();
        if(k==0)
        {
            res += s;
            return;
        }
        
        if(n<=k)
            return;
        
        int idx=0;
        for(int i=1;i<k+1;i++)
            if(s[idx]>s[i])
                idx = i;
        
        res += s[idx];
        helper(s.substr(idx+1, n-idx), k-idx, res);
    }
    string removeKdigits(string s, int k) 
    {
        /*string res = "";
        helper(s, k, res);
        int i;
        for(i=0;i<res.size();i++)
        {
            if(res[i]!='0')
                break;
        }
        if(i==res.size())
            return "0";
        string ans = res.substr(i);
        return ans;*/
        
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k > 0 && st.top() > s[i])
                st.pop(), k--;
            if(!st.empty() or s[i]!='0')
                st.push(s[i]);
        }
        
        while(!st.empty()&&k--)
            st.pop();
        if(st.empty())
            return "0";
            
        while(!st.empty())
            s[n-1]=st.top(), st.pop(), n--;
        
        return s.substr(n);
    }
