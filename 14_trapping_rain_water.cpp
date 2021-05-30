O(n) Time and O(n) Space
int trappingWater(int arr[], int n)
    {
        int* left = new int[n];
        int* right = new int[n];
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1], arr[i]);
            right[n-i-1] = max(right[n-i], arr[n-i-1]);
        }
        
        int area = 0;
        for(int i=0;i<n;i++)
            area += (min(left[i], right[i])-arr[i]);
        return area;
    }
O(n) Time and O(1) Space
int trappingWater(int arr[], int n)
    {
        int l=0, r=n-1;
        int left_max = 0, right_max=0;
        int area =0;
        while(l<=r)
        {
            if(left_max<=right_max)
            {
                area += max(0, left_max-arr[l]);
                left_max = max(left_max, arr[l]);
                l++;
            }
            else
            {
                area += max(0, right_max-arr[r]);
                right_max = max(right_max, arr[r]);
                r--;
            }
        }
        return area;
    }
