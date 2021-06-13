int maxLength(string s)
    {
        int n = s.size();
        /*stack<int>st;
        st.push(-1);
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
                
            else
            {
                if(!st.empty())
                    st.pop();
                
                if(!st.empty())
                {
                    if(max_len<i-st.top())
                        max_len=i-st.top();
                }    
                else
                    st.push(i);
            }
        }
        
        return max_len;*/
        
        int left=0, right=0, max_len = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                left++;
            else right++;
            
            if(left==right)
            {
                if(max_len<2*right)
                    max_len = 2*right;
            }
            
            else if(left<right)
                left=0, right=0;
        }
        
        left=0, right=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            else right++;
            
            if(left==right)
            {
                if(max_len<2*left)
                    max_len = 2*left;
            }
            
            else if(left>right)
                left=0, right=0;
        }
        return max_len;
    }
