int maxIndexDiff(int arr[], int n) 
    {
        int* leftmin = new int[n]; // smallest element from index 0 to i included
        int* rightmax = new int[n]; // largest element from index n-1 to i included
        leftmin[0] = arr[0];
        rightmax[n-1] = arr[n-1];
        for(int i=1;i<n;i++)
        {
            leftmin[i] = leftmin[i-1]<arr[i]?leftmin[i-1]:arr[i];
            rightmax[n-i-1] = rightmax[n-i]>arr[n-i-1]?rightmax[n-i]:arr[n-i-1];
        }
        
        int diff = INT_MIN;
        for(int i=0, j=0; i<n&&j<n; )
        {
            if(leftmin[i]<=rightmax[j])
            {
                diff = diff>(j-i)?diff:(j-i);
                j++;
            }
            else
                i++;
        }
        return diff;
    }
