void productPuzzle(int a[], int n)
{
    // to hold sum of all values
    long double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long double)log10(a[i]);

    // output product for each index
    // antilog to find original product value
    for (int i = 0; i < n; i++)
        cout << (int)(EPS + pow((long double)10.00,
                                sum - log10(a[i])))
             << " ";
}

vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        int left=1;
        int right =1;
        vector<int>ans(n,1);
        
        for(int i=0;i<n;i++)
        {
            ans[i]*=left;
            left*=nums[i];
            ans[n-1-i]*=right;
            right*=nums[n-1-i];
        }
        
        return ans;
    }
