bool precedence(char op1, char op2)
    {
        if (op1 == '^')
            return true; // op1 > op2
    
        if (op1 == '*' or op1 == '/')
            return (op2 != '^');
    
        if (op1 == '+' or op1 == '-')
            return (op2 == '+' or op2 == '-');
    
        else
            return false;
    }
    
    string infixToPostfix(string s)
    {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                ans += s[i];
    
            else
            {
                if (s[i] == '(')
                    st.push(s[i]);
    
                else if (s[i] == ')')
                {
                    while (st.top() != '(' && !st.empty())
                        ans += st.top(), st.pop();
                    st.pop();
                }
    
                else
                {
                    while (!st.empty() && st.top() != '(' && precedence(st.top(), s[i]))
                        ans += st.top(), st.pop();
                    st.push(s[i]);
                }
            }
        }
        while (!st.empty())
            ans += st.top(), st.pop();
        return ans;
    }
