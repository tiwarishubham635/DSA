vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int>dq;
        vector<int>ans;
        int mx = INT_MIN, i;
        for(i=0;i<k;i++)
        {
            while(dq.size() && arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for(i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);
            if(dq.size()&&dq.front()<=(i-k))
                dq.pop_front();
                
            while(dq.size() && arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
