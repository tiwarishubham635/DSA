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
For postfix to infix, just travel from i = 0 to size and when an operator is found, push s2+operator+s1 in the stack.
