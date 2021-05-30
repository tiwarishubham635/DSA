int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        int major=nums[0], ct=1;
        for(int i=1;i<n;i++)
        {
            if(ct==0)
            {
                ct++;
                major = nums[i];
            }
            else if(nums[i]==major)
                ct++;
            else
                ct--;
        }
        return major;
    }
