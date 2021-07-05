string nextPalin(string N)
    {
        //complete the function here
        // for base case
        if (N.size() <= 3)
        {
            return "-1";
        }
        
        //for non-increasing case, if first half of
        //the string is non-increasing (or) second half
        //of the string is non-decreasing, then next higher
        //palindrome is not possible
        int m = (N.size()) / 2 - 1;
        bool flag = 0; int i;
        for (i = m - 1; i >= 0; i--)
        {
            if (N[i] < N[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return "-1";
        }
        m++; 
        //just find the next_permutation of first half string
        //copy this to second half of the striing in reverse manner
        // to make it a palindrome
        
        
        next_permutation(N.begin(), N.begin() + m);
        
        i = 0;
        int j = N.size() - 1;
        while (i < j)
        {
            N[j] = N[i];
            i++;
            j--;
        }
        return N;
    }
