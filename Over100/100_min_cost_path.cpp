int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        int dist = 0;
        while(pq.size())
        {
            dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            //cout<<x<<" "<<y<<" "<<dist<<": "<<endl;
            
            if(x==n-1&&y==m-1)
                return dist;
            
            for(int i=0;i<4;i++)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                //cout<<x1<<" "<<y1<<" ";
                
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&!visited[x1][y1])
                {
                    //cout<<dist+grid[x1][y1]<<endl;
                    pq.push({dist+grid[x1][y1], {x1,y1}});
                    visited[x1][y1]=1;
                }
            }
        }
        return dist;
    }
