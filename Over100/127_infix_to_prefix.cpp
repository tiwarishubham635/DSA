bool precedence(char op1, char op2)
{
    if (op1 == '^')
        return true; // op1 > op2

    if (op1 == '*' or op1 == '/')
        return (op2 == '+' or op2 == '-');

    if (op1 == '+' or op1 == '-')
        return false;

    else
        return false;
}

string infixToPrefix(string s)
{
    s = '('+s+')';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
    }
    stack<char> st;
    string ans = "";
    for (int i = s.size()-1;i>=0; i--)
    {
        if (isalpha(s[i]))
            ans = s[i]+ans;

        else
        {
            if (s[i] == '(')
                st.push(s[i]);

            else if (s[i] == ')')
            {
                while (st.top() != '(' && !st.empty())
                    ans = st.top()+ans, st.pop();
                st.pop();
            }

            else
            {
                while (!st.empty() && st.top() != '(' && precedence(st.top(), s[i]))
                    ans = st.top()+ans, st.pop();
                st.push(s[i]);
            }
        }
    }
    while (!st.empty())
        ans = st.top()+ans, st.pop();
    return ans;
}
