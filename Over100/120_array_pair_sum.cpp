bool canPair(vector<int> nums, int k) 
    {
        int n = nums.size();
        if(n&1)
            return false;
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++)
            mp[((nums[j])%k+k)%k]++;
        
        for(int i=0;i<n;i++)
        {
            int rem = ((nums[i] % k) + k) % k;
            if (2 * rem == k) 
            {
                if (mp[rem] % 2 != 0)
                    return false;
            }

            else if (rem == 0) 
            {
                if (mp[rem] & 1)
                    return false;
            }

            else if (mp[rem] != mp[k - rem])
                return false;
        }
        return true;
    }
