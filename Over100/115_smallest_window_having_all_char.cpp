string smallestWindow (string s, string t)
    {
        int m[256] = { 0 };

        int ans = INT_MAX; 
        int start = 0; 
        int count = 0;
      
        for (int i = 0; i < t.length(); i++) 
        {
            if (m[t[i]] == 0)
                count++;
            m[t[i]]++;
        }
    
        int i = 0;
        int j = 0;
    
        while (j < s.length()) 
        {
            // Calculations
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
    
            // Condition matching
            while (count == 0) 
            {
                // Storing ans
                if (ans > j - i + 1) 
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I

                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
            j++;
        }
    
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "-1";
    }
