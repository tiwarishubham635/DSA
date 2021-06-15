vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        /*for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                pq.push(arr[i][j]);
            }
        }
        vector<int>ans(k*k);
        for(int i=k*k-1;i>=0;i--)
        {
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;*/
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i][0],i});
        }
        
        vector<int>size(k,1);
            
        vector<int>ans;
        while(pq.size())
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.first);
            if(k>size[p.second])
            {
                //cout<<p.first<<" hi"<<endl;
                pq.push({arr[p.second][size[p.second]], p.second});
                size[p.second]++;
            }
        }
        return ans;
    }
