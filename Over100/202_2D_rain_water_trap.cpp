int trapRainWater(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        
        priority_queue< pair< int, pair<int, int> >, 
        vector < pair< int, pair<int, int> > >, greater< pair< int, pair<int, int> > > >pq;
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            pq.push({ arr[i][0], {i,0} }), vis[i][0]=1;
            
            if(m!=1)
                pq.push({ arr[i][m-1], {i,m-1} }), vis[i][m-1]=1;
        }
        
        for(int i=0;i<m;i++)
        {
            pq.push({ arr[0][i], {0,i} }), vis[0][i]=1;
            
            if(m!=1)
                pq.push({ arr[n-1][i], {n-1, i} }), vis[n-1][i]=1;
        }
        
        int water = 0;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        int min_boundary_height = 0;
        while(pq.size())
        {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            min_boundary_height = max(min_boundary_height, val);
            
            for(int i=0;i<4;i++)
            {
                int row = r + dx[i];
                int col = c + dy[i];
                
                if(row>=0&&row<n&&col>=0&&col<m&&vis[row][col]==0)
                {
                    pq.push({ arr[row][col], {row, col} });
                    vis[row][col]=1;
                    
                    if(min_boundary_height > arr[row][col])
                        water += (min_boundary_height - arr[row][col]);
                }
            }
        }
        return water;
    }
