string prefix_to_infix(string s)
{
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(isalpha(s[i]))
        {
            string s1 = "";
            s1 += s[i];
            st.push(s1);
        }
        
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push('('+s1+s[i]+s2+')');
        }
    }
    return st.top();
}
