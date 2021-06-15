bool dfs(int index, int sum, vector<int>& nums, bitset<15>&track)
    {
        // side construction reached, so return true
        if(sum==0) return true;
        
        // loop through index to nums length
        for(int i=index; i<nums.size();i++)
        {
            // use unused item and check if sum-nums[i]>=0 and call DFS
            // if ith item can not make side then ignore and check with using next unused item
            if(!track[i] && sum-nums[i]>=0)
            {
                // set ith item as used
                track[i] = true;
                
                if(dfs(i+1,sum-nums[i],nums,track)) return true;
                
                // restore ith item as unused
                track[i] = false;
            }
        }
        
        // no side construction possible and so return false
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        
        // no possible square
        if(nums.size()==0) return false;
        
        int sum = 0;
        
        // get sum of all matches length
        for(int i=0;i<nums.size();i++)
            sum+= nums[i];
        
        // if sum is zero or sum not divisible by 4 then no possible sqaure
        if(sum==0 || sum%4) return false;
        
        // square side
        int side = sum/4;
        
        // sort nums array in descending order so we can make side using larger length first
        sort(nums.begin(),nums.end(),greater<int>());
        
        // track used item of nums array
        bitset<15>track;
        
        // check if we can make 3 side from nums array
        for(int i=0;i<3;i++)
        {
            // call DFS from start to check if side is possible to construct using unused items of nums array
            // if side is not possible to construct then no possbile square
            if(!dfs(0,side,nums,track))
                return false;
        }
                
        // 3 side constructed and so square possible
        return true;
    }
