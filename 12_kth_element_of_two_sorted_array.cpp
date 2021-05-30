O(n+m) Approach
	int kthElement(int arr1[], int arr2[], int n, int m, int ct)
    {
        int i, j, k;
        for(i=0, j=0, k=0; i<n&&j<m;)
        {
            if(arr1[i]<arr2[j])
            {
                k++;
                if(k==ct)
                    return arr1[i];
                i++;
            }
            else
            {
                k++;
                if(k==ct)
                    return arr2[j];
                j++;
            }
        }
        if(i<n)
        {
            while(i<n)
            {
                k++;
                if(k==ct)
                    return arr1[i];
                i++;
            }
        }
        
        else if(j<m)
        {
            while(j<m)
            {
                k++;
                if(k==ct)
                    return arr2[j];
                j++;
            }
        }
        return arr2[m-1];
    }

O(logn + logm) Approach

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n==0)
            return arr2[k-1];
        if(m==0)
            return arr1[k-1];
        
        int mid1 = n/2, mid2 = m/2;
        if(mid1 + mid2 < k-1)
        {
            if(arr1[mid1]<arr2[mid2])
                return kthElement(arr1+mid1+1, arr2, n-mid1-1, m, k-mid1-1);
            else
                return kthElement(arr1, arr2+mid2+1, n, m-mid2-1, k-mid2-1);
        }
        else
        {
            if(arr1[mid1]<arr2[mid2])
                return kthElement(arr1, arr2, n, mid2, k);
            else
                return kthElement(arr1, arr2, mid1, m, k);
        }
        return 0;
}

O(k) approach

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(arr2, arr1, m, n, k);
        if(n==0)
            return arr2[k-1];
        
        if(k==1)
            return min(arr1[0], arr2[0]);
            
        int i = min(n, k/2), j = min(m, k/2);
        if(arr1[i-1]>arr2[j-1])
            return kthElement(arr1, arr2+j, n, m-j, k-j);
        else
            return kthElement(arr1+i, arr2, n-i, m, k-i);
    }
