void helper(int* arr, int s, int e, vector<int>&ans)
    {
        if(s>e)
            return;
        int mid = (s+e)/2;
        ans.push_back(arr[mid]);
        helper(arr,s,mid-1,ans);
        helper(arr,mid+1,e, ans);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) 
    {
        int* arr = new int[nums.size()];
        for(int i=0;i<nums.size();i++)
            arr[i] = nums[i];
        vector<int>ans;
        helper(arr, 0, nums.size()-1, ans);
        return ans;
    }
