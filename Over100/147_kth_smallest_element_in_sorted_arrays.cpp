int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = matrix.size();
        /*priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {    //cout<<matrix[i][0]<<" "<<i<<endl;
            pq.push({matrix[i][0], i});
        }
        
        vector<int>size(n,1);
        
        int ct=0;
        pair<int,int>p;
        while(pq.size())
        {
            p=pq.top();
            pq.pop();
            if(ct==k-1)
                return p.first;
            
            if(matrix[p.second].size()>size[p.second])
            {
                pq.push({matrix[p.second][size[p.second]], p.second});
                size[p.second]++;
            }
            ct++;
        }
        if(ct==k-1)
            return p.first; 
        return -1;*/
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(l<=r)
        {
            int mid = (l+r)/2;
            int ct=0;
            for(int i=0;i<n;i++)
            {
                ct += upper_bound(matrix[i].begin(), matrix[i].end(), mid)- matrix[i].begin();
                /*for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]<=mid)
                        ct++;
                }*/
            }
            if(ct<k)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
