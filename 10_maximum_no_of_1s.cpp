int findZeroes(int arr[], int n, int m) 
    {
        int l =0, r=0, zeroes=0, best = 0;
        while(r<n)
        {
            if(arr[r]==0)
                zeroes;
            if(zeroes<=m)
                r++;
            else
            {
                best = ((r-l)>best)?(r-l):best;
                while(zeroes>m)
                {
                    zeroes = arr[l]==0?zeroes-1:zeroes;
                    l++;
                }
                r++;
            }
        }
        return ((r-l)>best)?(r-l):best;
    }  
