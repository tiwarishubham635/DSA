int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r==grid.size()-1&&c==grid[r].size()-1)
        {
            return grid[r][c];
        }
            
        if(r>=0&&r<grid.size()&&c>=0&&c<grid[r].size()&&grid[r][c]!=INT_MAX)
        {
            int val = grid[r][c];
            grid[r][c] = INT_MAX;
            
            int up = dfs(grid, r-1, c);
            int down = dfs(grid, r+1, c);
            int right = dfs(grid, r, c+1);
            int left = dfs(grid, r, c-1);
            
            int calls = min(up, min(down, min(left, right)));            
            grid[r][c] = val;
            if(calls==INT_MAX)
                return calls;
            
            return val+calls;
        }
        return INT_MAX;
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        /*int** dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=INT_MAX;
        }
        
        int d[][2] = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
        
        map<pair<int,int>, int>mp;
        dp[0][0] = grid[0][0];
        pair<int,int>p;
        p.first = 0, p.second = 0;
        mp[p]=0;
        while(mp.size())
        {
            p = (mp.begin())->first;
            int dist = (mp.begin())->second;
            mp.erase(mp.begin());
            
            for(int i=0;i<4;i++)
            {
                int x = p.first + d[i][0];
                int y = p.second + d[i][1];
                
                if(x>=0&&x<n&&y>=0&&y<n)
                {
                    if(dp[x][y] > dp[p.first][p.second] + grid[x][y])
                    {
                        pair<int, int>p1;
                        p1.first = x;
                        p1.second = y;
                        dp[x][y] = dp[p.first][p.second] + grid[x][y];
                        mp[p1] = dp[p.first][p.second] + grid[x][y];
                    }
                }
            }
        }
        return dp[n-1][n-1];*/
        
        //return dfs(grid, 0, 0);
        
        int** dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=INT_MAX;
        }
        
        dp[n-1][n-1] = grid[n-1][n-1];
        
        /*for(int i=n-2;i>=0;i--)
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        
        for(int i=n-2;i>=0;i--)
            dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];*/
        
        for(int l=2;l<=n;l++)
        {
            for(int i=n-1;i>=n-l;i--)
            {
                for(int j=n-1;j>=n-l;j--)
                {
                    int val = dp[i][j];
                    if(i!=0)
                        dp[i][j] = min(dp[i][j], dp[i-1][j]);
                    if(i!=n-1)
                        dp[i][j] = min(dp[i][j], dp[i+1][j]);
                    if(j!=n-1)
                        dp[i][j] = min(dp[i][j], dp[i][j+1]);
                    if(j!=0)
                        dp[i][j] = min(dp[i][j], dp[i][j-1]);
                    
                    if(dp[i][j]!=val)
                        dp[i][j] += grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
