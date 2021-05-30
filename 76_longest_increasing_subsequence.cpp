int longestSubsequence_h(int n, int a[], int &max)
    {
        if (n == 1)
        {
            //cout << n << " " << 1 << " " << max << endl;
            return 1;
        }
    
        int ans = 1;
        for (int i = n - 1; i > 0; i--)
        {
            int possible = 1 + longestSubsequence_h(i, a, max);
            if ((a[n - 1] > a[i - 1]) && ans < possible)
                ans = possible;
        }
        if (ans > max)
            max = ans;
        //cout << n << " " << ans << " " << max << endl;
        return ans;
    }
    
    int pos(int* v, int l, int r, int val)
    {
       while ((r - l) > 1) 
       {
            int m = (r + l) / 2;
            if (v[m] >= val)
                r = m;
            else
                l = m;
        }
 
        return r;
    }
    
    int longestSubsequence(int n, int a[])
    {
        /*int max = 1;
        int ans = longestSubsequence_h(n, a, max);
        return max;*/
        
        /*int *ans = new int[n];
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] < a[i])
                {
                    int possibleAns = ans[j] + 1;
                    if (possibleAns > ans[i])
                    {
                        ans[i] = possibleAns;
                    }
                }
            }
        }

        int m = 0;
        for (int i = 0; i < n; i++)
            if (m < ans[i])
                m = ans[i];
        delete[] ans;
        return m;*/
        
        int* v = new int[n];
        for(int i=0;i<n;i++)
            v[i]=0;
        v[0]=a[0];
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(v[0]>a[i])
                v[0]=a[i];
            else if(v[len-1]<a[i])
                v[len++]=a[i];
            else
                v[pos(v, -1, len-1, a[i])]=a[i];
        }
        return len;
    }
