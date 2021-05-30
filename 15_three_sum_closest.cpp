O(n2) approach

int threeSumClosest(vector<int>& arr, int target) 
    {
        sort(arr.begin(), arr.end());
        int closest = INT_MAX;
        int n = arr.size();
        for(int i=0;i<n-2&&closest!=target;i++)
        {
            int ptr1 = i+1, ptr2 = n-1;
            while(ptr1<ptr2&&closest!=target)
            {
                int sum = arr[i]+arr[ptr1]+arr[ptr2];
                if(abs(1ll*target-sum)<abs(1ll*target-closest))
                    closest = sum;
                if(sum<target)
                    ptr1++;
                else
                    ptr2--;
            }
        }
        return closest;
    }
