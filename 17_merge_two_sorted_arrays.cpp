 O(nlogn + mlogm) Approach:

void merge(int arr1[], int arr2[], int n, int m) 
	{
	    int ix=0, iy=0, k=n-1;
	    while(ix<=k&&iy<m)
	    {
	        if(arr1[ix]<=arr2[iy])
    	    {
    	        ix++;
    	    }
    	    else
    	    {
    	        swap(arr1[k], arr2[iy]);
    	        iy++;
    	        k--;
    	    }
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	}

	Skipping numbers approach - O(n+m) Approach:


int nextGap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
    
    void merge(int *arr1, int *arr2, int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap);
             gap > 0; gap = nextGap(gap))
        {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);
    
            // comparing elements in both arrays.
            for (j = gap > n ? gap - n : 0;
                 i < n && j < m;
                 i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
    
            if (j < m)
            {
                // comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }

O(n+m) Approach - Two values at a place

	void merge(int arr1[], int arr2[], int n, int m) 
	{
	    int max_ele = arr1[0];
	    for(int i=1;i<n;i++)
	        if(max_ele < arr1[i])
	            max_ele = arr1[i];
	            
	   for(int i=0;i<m;i++)
	        if(max_ele < arr2[i])
	            max_ele = arr2[i];
	            
	   max_ele++;//to have unique remainders 
	   int i,j,k;
	   for(i=0, j=0,k=0;i<n&&j<m;)
	   {
	       int e1 = arr1[i]%max_ele; // old value of arr1[i]
	       int e2 = arr2[j]%max_ele; // old value of arr2[j]
	       if(e1<=e2)
	       {
	           if(k<n)
	            arr1[k] += e1*max_ele;
	           else
	            arr2[k-n] += e1*max_ele;
	           k++; i++;
	       }
	       else
	       {
	           if(k<n)
	            arr1[k] += e2*max_ele;
	           else
	            arr2[k-n] += e2*max_ele;
	           k++; j++;
	       }
	   }
	   
	   while(i<n)
	   {
	       if(k<n)
	        arr1[k] += (arr1[i]%max_ele)*max_ele;
	       else
	        arr2[k-n] += (arr1[i]%max_ele)*max_ele;
	       k++; i++;
	   }
	   
	   while(j<m)
	   {
	       if(k<n)
	        arr1[k] += (arr2[j]%max_ele)*max_ele;
	       else
	        arr2[k-n] += (arr2[j]%max_ele)*max_ele;
	       k++; j++;
	   }
	   
	   for(int i=0;i<n;i++)
	    arr1[i] = arr1[i]/max_ele;
	    
	   for(int j=0;j<m;j++)
	    arr2[j] = arr2[j]/max_ele;
	}
