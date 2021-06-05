string shortestPalindrome(string s)
    {
        int n = s.size();
        string x = s;
        for (int i = 0; i < n / 2; i++)
            swap(x[i], x[n - 1 - i]);
        string y = s + '#' + x;
        int m = y.size();
        int *lps = new int[m];
        lps[0] = 0;
        int len = 0, i = 1;
        while (i < m)
        {
            if (y[len] == y[i])
            {
                len++;
                lps[i] = len;
                i++;
            }

            else
            {
                if (len == 0)
                    lps[i] = 0, i++;
                else
                    len = lps[len - 1];
            }
        }

        x = s.substr(lps[m - 1]);
        for (int i = 0; i < (x.size()) / 2; i++)
            swap(x[i], x[x.size() - 1 - i]);
        return x + s;
    }
