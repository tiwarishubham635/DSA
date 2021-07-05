string remove(string &s)
    {
        int i = 0;
        while (i < int(s.size()))
        {
            int trigger = 0;
            int j = i;
            if (s[j] == s[j + 1])
            {
                trigger = 1;
                while (s[i] == s[j + 1])
                    j++;
            }
            if (trigger == 1)
            {
                s.erase(s.begin() + i, s.begin() + j + 1);
                i--;
            }
            
            i++;
        }
        for (i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                remove(s);
        }
        return s;
    }
