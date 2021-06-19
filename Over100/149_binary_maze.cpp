int shortestDistance(int n, int m, vector<vector<int>> arr, int x, int y) 
    {
        if(arr[0][0]==0)
            return -1;
        
        if(x==0&y==0)
            return 0;
        
        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};
        vector<vector<int>>visited(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;
        q.push({{0,0},0});
        visited[0][0] = 1;
        while(q.size())
        {
            int xi = q.front().first.first;
            int yi = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            
            //cout<<xi<<" "<<yi<<endl;
            
            if(xi==x&&yi==y)
                return cost;
            
            for(int i=0;i<4;i++)
            {
                int x_new = xi + row[i];
                int y_new = yi + col[i];
                
                //cout<<x_new<<" "<<y_new<<", ";
                
                if(x_new>=0&&x_new<n&&y_new>=0&&y_new<m&&arr[x_new][y_new]&&!visited[x_new][y_new])
                    visited[x_new][y_new]=1, q.push({{x_new,y_new},1+cost});
            }
        }
        return -1;
    }
