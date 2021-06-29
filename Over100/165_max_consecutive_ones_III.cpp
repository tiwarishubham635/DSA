int longestOnes(vector<int>& nums, int k) 
    {
        int l = 0, r = 0;
        int z = 0;
        int len = 0;
        
        while(r<nums.size())
        {
            if(nums[r]==0)
                z++;
            
            while(z>k)
            {
                if(nums[l]==0)
                    z--;
                l++;
            }
            
            len = max(len, r-l+1);
            r++;
        }
        
        return len;
    }
