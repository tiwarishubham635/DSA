string removeDuplicates(string s) //azxxzy
    {
        /*stack<char>st;
        for(int i=0;i<s.size();i++) // st = 'a''y'
        {
            char ch = s[i];
            if(st.empty() or st.top()!=ch)
                st.push(ch);
            else
                st.pop();
        }
        string ans = "";
        while(st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;*/
        
        int i =0,n=s.length();
        for(int j =0;j<n;j++,i++)
        {
            s[i]=s[j];
            if(i>0 && s[i-1]==s[i])
                i-=2;
            
        }
        return s.substr(0,i);
    }
