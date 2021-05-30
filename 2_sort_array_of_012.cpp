2. 
void sort012(int a[], int n)
    {
        int low = 0;
        int high = n - 1;
        int mid = 0;
     
        while (mid <= high) 
        {
            if(a[mid]==0)
            {
                swap(a[low++], a[mid++]);
            }
                    
            else if(a[mid]==1)
            {
                mid++;
            }
            
            else
            {
                swap(a[mid], a[high--]);
            }
        }
    }
