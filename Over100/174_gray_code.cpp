/*vector<int> grayCode(int n) 
    {
        vector<int>ans;
        unordered_set<int>v;
        int start = 0;
        v.insert(start);
        ans.push_back(start);  
        
        while(v.size()<(1<<n))
        {
            for(int i=0;i<n;i++)
            {
               int next = start^(1<<i); 
               if(v.find(next)==v.end())
               {
                   v.insert(next);
                   ans.push_back(next);
                   start = next;
                   break;
               }
            }
        }
        
        return ans;
    }*/
    
    vector<int> grayCode(int n) 
    {
        if(n==1)
        {
            vector<int> tmp;
            tmp.push_back(0);
            tmp.push_back(1);
            return tmp;
        }
        vector<int> nums = grayCode(n-1);
        for(int i = nums.size()-1; i>=0; i--){
            nums.push_back(nums[i] | (1<<(n-1)));
        }
        return nums;
    }
