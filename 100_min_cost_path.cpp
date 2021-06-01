int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int** dp = new int*[n];
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
        return dp[n-1][n-1];
    }
