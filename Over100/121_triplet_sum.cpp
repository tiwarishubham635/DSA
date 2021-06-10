bool find3Numbers(int a[], int n, int x)
    {
        /*sort(a, a+n);
        for(int i=0;i<n;i++)
        {
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = a[i] + a[j] + a[k];
                if(sum==x)
                    return true;
                
                if(sum<x)
                    j++;
                
                else
                    k--;
            }
        }
        return false;*/
        
        for(int i=0;i<n;i++)
        {
            unordered_set<int>s;
            for(int j=i+1;j<n;j++)
            {
                if(s.find(x-a[i]-a[j])!=s.end())
                    return true;
                s.insert(a[j]);
            }
        }
        return false;
    }
