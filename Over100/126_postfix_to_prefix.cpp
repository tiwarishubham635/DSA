string postfix_to_prefix(string s)
{
    stack<string>st;
    for(int i=0;i<s.size();i++)
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
            st.push(s[i]+s2+s1);
        }
    }
    return st.top();
}
Similarly for prefix to postfix, trvael from i = n-1 to 0 and when s[i] is operator, push s1+s2+s[i] into stack.
