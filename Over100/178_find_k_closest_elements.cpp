vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        /*If the element at arr[mid] is closer to x than arr[mid + k], then that means arr[mid + k], as well as every element to the right of it can never be in the answer. This means we should move our right pointer to avoid considering them. The logic is the same vice-versa - if arr[mid + k] is closer to x, then move the left pointer.*/
        
        int n = arr.size();
        vector<int>ans;
        int l=0, r = n-k;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(x - arr[mid] > arr[mid+k] - x)
                l = mid+1;
            else
                r = mid;
        }
        for(int i=l;i<l+k;i++)
            ans.push_back(arr[i]);
        return ans;
    }
