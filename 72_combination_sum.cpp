void findpair(vector<int> &arr, int b, vector<vector<int>> &ans, vector<int>r, int i)
    {
        if (b == 0) 
        {
            ans.push_back(r);
            return;
        }
     
        while (i < arr.size() && b >= arr[i]) 
        {
            r.push_back(arr[i]);
            findpair(arr, b - arr[i], ans, r, i+1);
            i++;
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int n, int b)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        vector<int>r;
        findpair(arr, b, ans, r, 0);
        map<vector<int>,int>mp;
        for(int i=0;i<ans.size();i++)
            mp[ans[i]]++;
        vector<vector<int>>final;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            final.push_back(i->first);
        }
        return final;
    }
